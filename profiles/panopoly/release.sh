#!/bin/sh
# Script to generate release notes for the Panopoly installation profile
# This command expects to be run within the Panopoly profile.
# To use this command you must have Git Release Notes for Drush installed
# @see https://drupal.org/project/grn

if [ $# -ne 2 ]; then
  echo "Usage $0 previous_tag latest_tag"
  exit 1
fi

BASE_PATH=`pwd`

# Create a directory to store all the release notes
mkdir $BASE_PATH/release_notes/

echo "creating release notes for panopoly"

echo "<p><strong>Instructions on how to upgrade:</strong></p>" > $BASE_PATH/release_notes/panopoly.html

echo "<ol>" >> $BASE_PATH/release_notes/panopoly.html
echo "<li>Download the latest packaged version of Panopoly from Drupal.org. This will include updated versions of all of Panopoly's bundled modules, themes, and libraries.</li>" >> $BASE_PATH/release_notes/panopoly.html
echo "<li>Upgrade your existing site to use the code you just downloaded. Check out these instructions for more information: <a href='http://drupal.org/node/1223018'>http://drupal.org/node/1223018</a></li>" >> $BASE_PATH/release_notes/panopoly.html
echo "<li>Backup your database and run update.php *TWICE* on your site. This may perform several database updates for Panopoly and its bundled apps and modules.</li>" >> $BASE_PATH/release_notes/panopoly.html
echo "<li>Navigate to the admin screen for Features (admin/structure/features) and revert any overridden features (unless you have intentionally made overrides you want to keep).</li>" >> $BASE_PATH/release_notes/panopoly.html
echo "</ol>" >> $BASE_PATH/release_notes/panopoly.html

echo "<strong>Updates in this release:</strong>" >> $BASE_PATH/release_notes/panopoly.html

# Create the release notes for the distro
drush rn $1 $2 >> $BASE_PATH/release_notes/panopoly.html

# For each module, create some html release notes.
for MODULE in panopoly_admin panopoly_core panopoly_images panopoly_magic panopoly_pages panopoly_search panopoly_theme panopoly_users panopoly_widgets panopoly_wysiwyg
do
  MODULENAME=`echo ${MODULE//_/ }`
  echo "creating release notes for $MODULENAME"
	cd modules/panopoly/$MODULE
  drush rn $1 $2 > $BASE_PATH/release_notes/$MODULE.html
  
  echo "<h2>$MODULENAME</h2>" >> $BASE_PATH/release_notes/panopoly.html
  drush rn $1 $2 >> $BASE_PATH/release_notes/panopoly.html
  
  cd $BASE_PATH
done
