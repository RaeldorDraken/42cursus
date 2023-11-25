# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 10:43:18 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/25 18:19:52 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@mkdir -p /home/eros-gir/data/mysql
	@mkdir -p /home/eros-gir/data/wordpress
	@docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	@docker compose -f ./srcs/docker-compose.yml down

clean: down
	@docker compose -f ./srcs/docker-compose.yml down -v
	@docker system prune --all --force
	@docker volume prune --all --force
	@docker network rm eros-girnet

fclean: clean
	@sudo rm -rf /home/eros-gir/data

.PHONY: all down clean fclean
