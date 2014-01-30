#!/bin/sh
# Script to rebuild the Panopoly installation profile
# This command expects to be run within the Panopoly profile.
# To use this command you must have `drush make` and `git` installed.

if [ -f drupal-org.make ]; then

  echo ' ___   ___   ___'
  echo '|___| |   | |   |'
  echo ' ___  |   | |___|'
  echo '|   | |   |  ___ '
  echo '|   | |___| |___|'
  echo '|   |  _________ '
  echo '|___| |_________|'
  echo ''
  echo '================='
  echo '    Panopoly     '
  echo '================='

  echo "\nThis command can be used to rebuild the installation profile in place.\n"
  echo "  [1] Rebuild profile in place in release mode (latest stable release)"
  echo "  [2] Rebuild profile in place in development mode (latest dev code)"
  echo "  [3] Rebuild profile in place in development mode (latest dev code with .git working-copy)\n"
  echo "Selection: \c"
  read SELECTION

  if [ $SELECTION = "1" ]; then

    echo "Building Panopoly install profile in release mode..."
    drush make --no-core --no-gitinfofile --contrib-destination=. drupal-org-release.make

  elif [ $SELECTION = "2" ]; then

    echo "Building Panopoly install in development mode (latest dev code)..."
    drush make --no-core --no-gitinfofile --contrib-destination=. drupal-org.make

  elif [ $SELECTION = "3" ]; then

    echo "Building Panopoly install profilein development mode (latest dev code with .git working-copy)"
    drush make --working-copy --no-core --no-gitinfofile --contrib-destination=. drupal-org-dev.make

  else
   echo "Invalid selection."
  fi
else
  echo 'Could not locate file "drupal-org.make"'
fi
