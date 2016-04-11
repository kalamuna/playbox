#!/bin/bash

# Wait for the database to be up.
while ! mysqladmin ping -h"$MYSQL_HOST" --silent; do
    sleep 1
done

# Install using Drush.
drush site-install --db-url="mysql://$MYSQL_USER:$MYSQL_PASSWORD@$MYSQL_HOST/$MYSQL_DATABASE" -y minimal

# Display a login link.
drush uli --no-browser

# Start up the web server.
apache2-foreground
