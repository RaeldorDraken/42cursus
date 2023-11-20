# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 10:35:21 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/19 10:36:56 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@mkdir -p /home/eros-gir/data/mysql /home/eros-gir/data/wordpress
	@docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	@docker compose -f ./srcs/docker-compose.yml down

clean:
	@docker stop $$(docker ps -qa)
	@docker system prune --all --force
	@docker volume prune --all --force
	@docker volume rm $$(docker volume ls -q)
	@docker network rm eros-girnet
	@sudo rm -rf /home/eros-gir/data

.PHONY: all down clean
