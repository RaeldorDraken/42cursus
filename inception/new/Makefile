# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:48:12 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/16 23:05:20 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	@docker compose -f ./srcs/docker-compose.yml down

clean:
	@rm -rf /home/eros-gir/data/mysql/*
	@rm -rf /home/eros-gir/data/wordpress/*
	@docker stop $$(docker ps -qa)
	@docker rm $$(docker ps -qa)
	@docker rmi $$(docker images -qa)
	@docker volume rm $$(docker volume ls -q)
	@docker network rm eros-girnet

.PHONY: all down clean