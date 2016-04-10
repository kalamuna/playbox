FROM drupal:8.1-apache

# Provide our own Drupal web root
RUN rm -rf /var/www/html
VOLUME /var/www/html
