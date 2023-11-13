# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    create_wordpress.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 10:48:46 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/13 10:49:33 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

if [ -f ./wp-config.php ]
then
	echo "wordpress already downloaded"
else

	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	mv wordpress/* .
	rm -rf latest.tar.gz
	rm -rf wordpress

	sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
	sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
	sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
	sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
	cp wp-config-sample.php wp-config.php

fi

exec "$@"