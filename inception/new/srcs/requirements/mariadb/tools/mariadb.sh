#!/bin/bash

service mysql start

if [ ! -d /var/lib/mysql/${MYSQL_DATABASE} ]; then
    mysql -u ${MYSQL_ROOT_USER} -p"${MYSQL_ROOT_PASSWORD}" -h localhost -e "CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\`;"
    mysql -u ${MYSQL_ROOT_USER} -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
    mysql -u ${MYSQL_ROOT_USER} -p"${MYSQL_ROOT_PASSWORD}" -e "GRANT ALL ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD' WITH GRANT OPTION;"
    mysql -u ${MYSQL_ROOT_USER} -p"${MYSQL_ROOT_PASSWORD}" -e "FLUSH PRIVILEGES;"
    mysql -u ${MYSQL_ROOT_USER} -p"${MYSQL_ROOT_PASSWORD}" -e "ALTER USER '${MYSQL_ROOT_USER}'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
fi

mysqladmin -u ${MYSQL_ROOT_USER} --password="${MYSQL_ROOT_PASSWORD}" shutdown

mysqld