# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mariadb.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 10:54:47 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/13 10:55:06 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

mysql_install_db

/etc/init.d/mysql start

if [ -d "/var/lib/mysql/$MYSQL_DATABASE" ]
then 

	echo "Database already exists"
else

mysql_secure_installation << _EOF_

Y
root4life
root4life
Y
n
Y
Y
_EOF_

echo "GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;" | mysql -uroot

echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE; GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'; FLUSH PRIVILEGES;" | mysql -u root

mysql -uroot -p$MYSQL_ROOT_PASSWORD $MYSQL_DATABASE < /usr/local/bin/wordpress.sql

fi

/etc/init.d/mysql stop

exec "$@"