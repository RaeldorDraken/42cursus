FROM debian:bullseye

EXPOSE 9000

RUN apt-get update && apt-get install -y \
	curl \
	mariadb-client \
	php7.4-fpm \
	php7.4-mysqli

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
  && chmod +x wp-cli.phar \
  && mv wp-cli.phar /usr/local/bin/wp

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

RUN mkdir -p /run/php
RUN chmod 777 /run/php

COPY ./create_wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/create_wordpress.sh

WORKDIR /var/www/html/

ENTRYPOINT ["/usr/local/bin/create_wordpress.sh"]

#CMD ["/usr/sbin/php-fpm7.3", "-F"]