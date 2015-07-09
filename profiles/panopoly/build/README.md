Phing Drupal Distributions
==========================

Phing build scripts for working with Drupal distributions.

To use with your distribution:

1. Copy this directory into a sub-directory called 'build' in your profile

2. Copy the 'examples/build.xml', 'examples/build.default.properties' and
   'examples/composer.json' to the top-level directory of your profile.

3. Modify 'build.default.properties' to suit the needs of your distro. If you
   need to change some settings just for you, create a 'build.properties' file.

4. Download Composer. See https://getcomposer.org/download/#main
   
5. Run 'composer install' or 'php composer.phar install' to install Phing and
   its dependencies.

6. Run 'bin/phing -l' to see what targets you can build!

