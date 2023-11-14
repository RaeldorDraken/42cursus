# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 10:40:20 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/14 10:43:01 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	@docker compose -f ./srcs/docker-compose.yml down

re:
	@docker compose -f srcs/docker-compose.yml up -d --build

clean: down
	-@docker stop $$(docker ps -qa)
	-@docker system prune --all --force
	-@docker volume prune --all --force
	-@docker volume rm $$(docker volume ls -q)
	@rm -rf /home/eros-gir/data/

.PHONY: all re down clean