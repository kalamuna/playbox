FROM drupal:8.1-apache

# Install PHP dependencies.
RUN apt-get update && apt-get install mysql-client -y

# Install Drupal Console, Drush and Composer.
RUN php -r "readfile('https://drupalconsole.com/installer');" > /usr/local/bin/drupal && chmod +x /usr/local/bin/drupal && drupal --version
RUN php -r "readfile('http://files.drush.org/drush.phar');" > /usr/local/bin/drush && chmod +x /usr/local/bin/drush && drush --version
RUN php -r "readfile('https://getcomposer.org/download/1.0.0/composer.phar');" > /usr/local/bin/composer && chmod +x /usr/local/bin/composer && composer --version

# Setup the Docker-Compose entrypoint.
COPY scripts/docker-compose.entry.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Provide our own Drupal web root.
RUN rm -rf /var/www/html
VOLUME ["/var/www/html"]
CMD ["/entrypoint.sh"]
