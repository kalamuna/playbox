#!/bin/bash

COMMAND=$1
EXIT_VALUE=0

##
# SCRIPT COMMANDS
##

# before-install
#
# Do some stuff before npm install
#
before-install() {
  if [ $TRAVIS_BRANCH == "master" ] &&
    [ $TRAVIS_PULL_REQUEST == "false" ] &&
    [ $TRAVIS_REPO_SLUG == "kalamuna/playbox" ]; then
    openssl aes-256-cbc -K $encrypted_739d46f84175_key -iv $encrypted_739d46f84175_iv -in ci/travis.id_rsa.enc -out $HOME/.ssh/travis.id_rsa -d
  fi
}

# before-script
#
# Install build dependencies
#
before-script() {
  composer update
  pear install pear/PHP_CodeSniffer
  phpenv rehash
}

# script
#
# Run the tests.
#
script() {
  # Lint check PHP files.
  find . -path "*/sites/all/*" \( -type f -name \*.inc -o -name \*.php -o -name \*.module -o -name \*.install \) -print0 | xargs -0 -n 1 -P 4 php -l
  # PHP_CodeSniffer using Drupal Coding Standard.
  phpcs --standard=./vendor/coder/coder/coder_sniffer/Drupal --ignore=*/panopoly_demo/* sites/all/*
}

# after-script
#
# Clean up after the tests.
#
after-script() {
  echo
}

# after-success
#
# Deploy
#
after-success() {
  if [ $TRAVIS_BRANCH == "master" ] &&
     [ $TRAVIS_PULL_REQUEST == "false" ] &&
     [ $TRAVIS_REPO_SLUG == "kalamuna/playbox" ]; then
    chmod 600 $HOME/travis.id_rsa
    eval "$(ssh-agent)"
    ssh-add $HOME/travis.id_rsa
    git config --global user.name "Kala C. Bot"
    git config --global user.email kalacommitbot@kalamuna.com
    git remote add upstream ssh://codeserver.dev.f0072597-f475-4513-af94-13a33b630923@codeserver.dev.f0072597-f475-4513-af94-13a33b630923.drush.in:2222/~/repository.git
    git add --all
    git commit -m "KALABOT BUILDING COMMIT ${TRAVIS_COMMIT} FROM ${TRAVIS_REPO_SLUG}"
    git push upstream master -f
  fi
}

# before-deploy
#
# Clean up after the tests.
#
before-deploy() {
  echo
}

# after-deploy
#
# Clean up after the tests.
#
after-deploy() {
  echo
}

##
# UTILITY FUNCTIONS:
##

# Sets the exit level to error.
set_error() {
  EXIT_VALUE=1
}

# Runs a command and sets an error if it fails.
run_command() {
  set -xv
  if ! $@; then
    set_error
  fi
  set +xv
}

##
# SCRIPT MAIN:
##

# Capture all errors and set our overall exit value.
trap 'set_error' ERR

# We want to always start from the same directory:
cd $TRAVIS_BUILD_DIR

case $COMMAND in
  before-install)
    run_command before-install
    ;;

  before-script)
    run_command before-script
    ;;

  script)
    run_command script
    ;;

  after-script)
    run_command after-script
    ;;

  after-success)
    run_command after-success
    ;;

  before-deploy)
    run_command before-deploy
    ;;

  after-deploy)
    run_command after-deploy
    ;;
esac

exit $EXIT_VALUE
