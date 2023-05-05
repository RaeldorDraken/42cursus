# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 09:43:01 by eros-gir          #+#    #+#              #
#    Updated: 2023/05/05 10:28:56 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_YELLOW=\033[0;33m
C_END=\033[0m

NAME = account

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp

HDRS = Account.hpp

all:$(NAME)

$(NAME): $(SRCS) $(HDRS)
	@echo "$(C_YELLOW)make account...$(C_END)"
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
