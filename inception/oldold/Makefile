# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 10:40:20 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/16 10:45:47 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DATA_DIRECTORIES := /home/eros-gir/data /home/eros-gir/data/mysql /home/eros-gir/data/wordpress

all:
	@mkdir -p $(DATA_DIRECTORIES)
	@chmod -R 777 $(DATA_DIRECTORIES)
	@docker compose -f srcs/docker-compose.yml up -d --build

down:
	@docker compose -f srcs/docker-compose.yml down

re: clean
	@mkdir -p $(DATA_DIRECTORIES)
	@chmod -R 777 $(DATA_DIRECTORIES)
	@docker compose -f srcs/docker-compose.yml up -d --build

clean: down
	-@docker stop $$(docker ps -qa)
	-@docker system prune --all --force
	-@docker volume prune --all --force
	-@docker volume rm $$(docker volume ls -q)
	sudo rm -rf $(DATA_DIRECTORIES)

fclean: clean

.PHONY: all re down clean create-directories