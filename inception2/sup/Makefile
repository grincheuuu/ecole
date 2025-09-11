.PHONY: up down ps clean fclean re logs

DIRECTORYDATA := /home/gschwart/data
DIRECTORYCOMPOSE := /home/gschwart/Inception/srcs/docker-compose.yml
WORDVOLUME := $(DIRECTORYDATA)/wordpress
MARIAVOLUME := $(DIRECTORYDATA)/database
GRAFANAVOLUME := $(DIRECTORYDATA)/grafana
NAME := Inception

SRCS_DIR = ./srcs

up: $(NAME)

$(NAME):
	@mkdir -p $(DIRECTORYDATA)
	@mkdir -p $(WORDVOLUME) $(MARIAVOLUME) $(GRAFANAVOLUME)
	@cd $(SRCS_DIR) && docker compose up --build -d --force-recreate

down:
	@cd $(SRCS_DIR) && docker compose -f $(DIRECTORYCOMPOSE) down

ps:
	@cd $(SRCS_DIR) && docker compose ps

clean:
	@cd $(SRCS_DIR) && docker compose -f $(DIRECTORYCOMPOSE) down --volumes --remove-orphans

fclean: clean
	@docker system prune -af --volumes
	@docker volume prune -f
	@sudo rm -rf $(WORDVOLUME) $(MARIAVOLUME) $(GRAFANAVOLUME)

cleanv:
	@cd $(SRCS_DIR) && docker compose -f $(DIRECTORYCOMPOSE) down --volumes --remove-orphans
	@docker volume prune -f
	@sudo rm -rf $(WORDVOLUME) $(MARIAVOLUME) $(GRAFANAVOLUME)


re: fclean up

logs:
	@cd $(SRCS_DIR) && sudo docker compose logs -f
