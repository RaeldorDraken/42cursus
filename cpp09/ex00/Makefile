# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:40:05 by eros-gir          #+#    #+#              #
#    Updated: 2024/01/05 19:32:19 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_YELLOW=\033[0;33m
C_END=\033[0m

NAME = btc

RM = rm -f
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -g -fsanitize=address

FILES = main BitcoinExchange

SRC = $(addsuffix .cpp, $(FILES))

vpath %.cpp 

OBJ = $(SRC:.cpp=.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))

%.o: %.cpp 
	@${CC} $(CFLAGS) -MMD -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME):: $(OBJ) Makefile
	@echo "$(C_YELLOW)make $(NAME)$(C_END)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(C_GREEN)Completed...$(C_END)"

clean:
	@echo "$(C_RED)cleaning obj and dep$(C_END)"
	@$(RM) $(OBJ) $(DEP)
	@echo "$(C_GREEN)FINISHED$(C_END)"


fclean: clean
	@echo "$(C_RED)cleaning executable$(C_END)"
	@$(RM) $(NAME)
	@echo "$(C_GREEN)FINISHED$(C_END)"

re:	fclean all

.PHONY: all clean fclean re

-include $(DEP)