# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 10:21:36 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/02 10:21:44 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster


RUN apt -y update && apt install -y nginx && apt install openssl -y

COPY ./tools/script.sh /


CMD [ "/script.sh" ]