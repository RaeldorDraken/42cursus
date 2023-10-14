# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 15:41:23 by eros-gir          #+#    #+#              #
#    Updated: 2023/10/14 17:24:26 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_YELLOW=\033[0;33m
C_END=\033[0m

NAME = nowWeAreTalking

CC = c++
FLAGS = -Wall -Wextra -Werror -Wno-implicit-fallthrough -std=c++98

SRCS = main.cpp Fixed.cpp
HDRS = Fixed.hpp

all:$(NAME)

$(NAME): $(SRCS) $(HDRS)
	@echo "$(C_YELLOW)make Now we're talking$(C_END)"
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
