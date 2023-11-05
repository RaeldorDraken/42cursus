# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 10:21:57 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/05 19:07:16 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update -y && apt-get install mariadb-server -y

COPY ./config/mariconfig.cnf /etc/mysql/mariadb.conf.d/

COPY ./config/script.sh /

CMD ["/script.sh"]