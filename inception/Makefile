# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 09:48:29 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/02 10:09:45 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: up

up:
	docker-compose up -f ./srcs/docker-compose.yml up -d

down:
	docker-compose down -f ./srcs/docker-compose.yml down

stop:
	docker-compose stop -f ./srcs/docker-compose.yml stop

start:
	docker-compose start -f ./srcs/docker-compose.yml start

status:
	docker ps