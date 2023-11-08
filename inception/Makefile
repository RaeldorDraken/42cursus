# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 09:48:29 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/07 11:07:54 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: up

up:
#aqui toca poner cosas para crear las carpetas de los containers
	docker-compose up -f ./srcs/docker-compose.yml up -d

down:
	docker-compose down -f ./srcs/docker-compose.yml down

stop:
	docker-compose stop -f ./srcs/docker-compose.yml stop

start:
	docker-compose start -f ./srcs/docker-compose.yml start

status:
	docker ps