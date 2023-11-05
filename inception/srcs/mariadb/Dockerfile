# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 10:21:57 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/05 19:25:19 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade && apt update -y && apt upgrade -y

RUN apt-get install mariadb-server -y

COPY ./config/mariconfig.cnf /etc/mysql/mariadb.conf.d/

COPY ./config/script.sh /

CMD ["/script.sh"]