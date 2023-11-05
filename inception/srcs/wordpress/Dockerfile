# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 10:20:39 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/05 19:16:32 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade && apt update -y && apt upgrade -y

RUN apt install php-fpm php-mysql -y && apt install curl -y

COPY ./config/script.sh /
COPY ./config/wp-config.php /

CMD ["/script.sh"]