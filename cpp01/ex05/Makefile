# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 15:41:23 by eros-gir          #+#    #+#              #
#    Updated: 2023/10/09 11:38:59 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_YELLOW=\033[0;33m
C_END=\033[0m

NAME = Harl

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Harl.cpp
HDRS = Harl.hpp

all:$(NAME)

$(NAME): $(SRCS) $(HDRS)
	@echo "$(C_YELLOW)make Harl 2.0$(C_END)"
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "$(C_GREEN)Completed...$(C_END)"

clean:
	@echo "$(C_RED)cleaning executable$(C_END)"
	@rm -rf $(NAME)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

fclean:
	@echo "$(C_RED)cleaning executable$(C_END)"
	@rm -rf $(NAME)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

re: fclean all

PHONY: all clean fclean re
