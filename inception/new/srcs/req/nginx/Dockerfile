# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 11:54:03 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/18 00:36:55 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:bullseye

RUN apt-get Update
RUN apt-get install -y nginx openssl

EXPOSE 443

COPY ./conf/nginx.conf /etc/nginx/sites-enabled/nginx.conf
COPY ./tools/nginx.sh /var/www/nginx.sh

RUN chmod +x /var/www/nginx.sh

ENTRYPOINT ["var/www/nginx.sh"]

CMD ["nginx", "-g", "daemon off;"]