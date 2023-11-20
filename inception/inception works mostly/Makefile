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
	@sudo rm -rf /home/eros-gir/data
	@docker network rm gemartinnet

.PHONY: all down clean
