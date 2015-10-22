#!/usr/bin/env python

import argparse
import requests
import subprocess
import tempfile
import shutil
import os
import re
import pprint
import yaml

DRUPAL_ORG_API_NODE_URL = 'https://www.drupal.org/api-d7/node/%s.json'

PANOPOLY_COMPONENT_MAP = {
    'Admin': 'panopoly_admin',
    'Core': 'panopoly_core',
    'Demo': 'panopoly_demo',
    'Images': 'panopoly_images',
    'Magic': 'panopoly_magic',
    'Pages': 'panopoly_pages',
    'Search': 'panopoly_search',
    'Tests / Continuous Integration': 'panopoly_test',
    'Theme': 'panopoly_theme',
    'Users': 'panopoly_users',
    'Widgets': 'panopoly_widgets',
    'WYSIWYG': 'panopoly_wysiwyg',
}

PANOPOLY_GITHUB_REPO = 'git@github.com:panopoly/panopoly.git'

PANOPOLY_DEFAULT_BRANCH = '7.x-1.x'

def capture_output(args):
    proc = subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = proc.communicate()
    return stdout + stderr

def get_issue_patch_files(issue_number):
    """Gets the patches against each Panopoly project from the givin issue number."""

    node = requests.get(DRUPAL_ORG_API_NODE_URL % issue_number).json()

    files = {}
    for value in node['field_issue_files']:
        if value['display'] == '1':
            file = requests.get(value['file']['uri'] + '.json').json()
            if not file['name'].endswith('.patch'):
                continue

            m = re.match(r'^panopoly[_-]([^_-]+)[_-]', file['name'])
            if m and ('panopoly_' + m.group(1)) in PANOPOLY_COMPONENT_MAP.values():
                component = 'panopoly_' + m.group(1)
            else:
                try:
                    component = PANOPOLY_COMPONENT_MAP[node['field_issue_component']]
                except KeyError:
                    raise Exception("Unable to identify project for patch based on name '%s' or issue component '%s'" % (file['name'], node['field_issue_component']))

            files[component] = file['url']

    return files

def makefile_replace_patches(filename, patch_files):
    lines = []

    # First, filter out all the patches.
    with open(filename, 'rt') as fd:
        for line in fd.readlines():
            if not re.match(r'^projects\[[^\]]+\]\[patch\]', line):
                lines.append(line)

    # Add our new patches.
    lines.append("\n")
    lines.append("; Adding patches:\n")
    for project, patch in patch_files.items():
        lines.append("projects[%s][patch][] = %s\n" % (project, patch))

    # Write out the file.
    with open(filename, 'wt') as fd:
        for line in lines:
            fd.write(line)

def travisyml_skip_upgrade_tests(filename, skip_all=True):
    with open(filename, 'rt') as fd:
        data = yaml.load(fd)

    # We always drop the matrix -> include.
    if data.has_key('matrix') and data['matrix'].has_key('include'):
        del data['matrix']['include']

    # Remove all but the first 'env' entry. The rest are upgrade tests.
    if skip_all:
        data['env']['matrix'] = [data['env']['matrix'][0]]
    else:
        data['env']['matrix'] = data['env']['matrix'][0:2]

    with open(filename, 'wt') as fd:
        yaml.dump(data, fd)

def git_patch_branch(git_repo, old_branch, new_branch, patch_files, issue_number=None, skip_upgrade_tests=False):
    """Create a new branch in the git repo (based on the old branch) using the given patch files."""

    # Determine if the available git supports the --no-single-branch argument.
    supports_no_single_branch = 'single-branch' in capture_output(['git', 'clone'])

    # Clone the git repo.
    temp_directory = tempfile.mkdtemp(prefix='create_test_branch.py-') 
    git_clone_args = ['git', 'clone', git_repo, temp_directory, '--branch', old_branch, '--depth', '1']
    if supports_no_single_branch:
        git_clone_args.append('--no-single-branch')
    subprocess.check_call(git_clone_args)
    os.chdir(temp_directory)

    try:
        if subprocess.call(['git', 'checkout', new_branch]) > 0:
            # We have to create the branch, because it doesn't exist.
            subprocess.check_call(['git', 'checkout', '-b', new_branch])
        else:
            # We have to merge from the old_branch to catch any changes.
            subprocess.check_call(['git', 'merge', old_branch, '--strategy', 'recursive', '-X', 'theirs'])

        # Replace all patch files with the given patch files.
        makefile_replace_patches('drupal-org.make', patch_files)

        # Remove the upgrade tests if requested.
        travisyml_skip_upgrade_tests('.travis.yml', skip_all=skip_upgrade_tests)

        # Make commit message.
        if issue_number:
            commit_message = 'Trying latest patches on Issue #%s: https://www.drupal.org/node/%s\n' % (issue_number, issue_number)
        else:
            commit_message = 'Trying latest patches:\n'
        for patch in patch_files.values():
            commit_message += ' - %s\n' % patch

        # Commit and push!
        subprocess.check_call(['git', 'commit', '-a', '-m', commit_message])
        subprocess.check_call(['git', 'push', 'origin', new_branch])
    finally:
        shutil.rmtree(temp_directory)
            
def main():
    parser = argparse.ArgumentParser(description='Create a branch which includes patches from a Drupal.org issue, in order to trigger Travis-CI to test them.')
    parser.add_argument('issue_number', type=int, help='The issue number to run the tests for')
    parser.add_argument('--git-repo', default=PANOPOLY_GITHUB_REPO, help='The git repo to commit to')
    parser.add_argument('--git-old-branch', default=PANOPOLY_DEFAULT_BRANCH, help='The branch in the git repo to start from')
    parser.add_argument('--git-new-branch', help='The branch in the git repo to create')
    parser.add_argument('--skip-upgrade-tests', dest='skip_upgrade_tests', action='store_true', default=False, help='If passed, this will only run tests on the current -dev, skipping the tests against upgraded versions')
    #parser.add_argument('--run-upgrade-tests', dest='skip_upgrade_tests', action='store_false', default=True, help='If passed, this will run not only the tests on the current -dev, but also against upgraded versions')
    args = parser.parse_args()

    patch_files = get_issue_patch_files(args.issue_number)

    if not args.git_new_branch:
        args.git_new_branch = 'issue-%s' % args.issue_number
        
    git_patch_branch(args.git_repo, args.git_old_branch, args.git_new_branch, patch_files, issue_number=args.issue_number, skip_upgrade_tests=args.skip_upgrade_tests)

if __name__ == '__main__': main()
