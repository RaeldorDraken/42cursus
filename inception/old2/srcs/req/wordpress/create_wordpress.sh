#!/bin/sh

if [ ! -f wp-config.php ]; then
	wp core download --allow-root 
	wp config create --dbname=$DATA_BASE_NAME --dbuser=$MARIADB_USER --dbpass=$MARIADB_USER_PASSWORD --dbhost=$DATA_BASE_HOSTNAME --allow-root
	wp core install --url=$DOMAIN_NAME --title="$WORDPRESS_TITLE" --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --skip-email --allow-root
	wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL --role=author --user_pass=$WORDPRESS_USER_PASSWORD --allow-root
	wp theme install twentytwentytwo --activate --allow-root
fi

/usr/sbin/php-fpm7.4 -F;


# if [ -f ./wp-config.php ]
# then
# 	echo "wordpress already downloaded"
# else

# 	wget http://wordpress.org/latest.tar.gz
# 	tar xfz latest.tar.gz
# 	mv wordpress/* .
# 	rm -rf latest.tar.gz
# 	rm -rf wordpress

# 	sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
# 	sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
# 	sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
# 	sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
# 	cp wp-config-sample.php wp-config.php

# fi

# exec "$@"