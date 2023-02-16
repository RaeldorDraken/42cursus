# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 14:48:15 by eros-gir          #+#    #+#              #
#    Updated: 2023/02/16 12:18:29 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_YELLOW=\033[0;33m
C_END=\033[0m

NAME = minishell

SRC = ./src/ms_main.c

HDR = ./incl/mslib.h ./libft/libft.h

LIBFTDIR = ./libft/

OBJ = $(SRC:.c=.o)

GC = gcc
FLAGS = -g -Wall -Wextra -Werror -lreadline

%.o: %.c $(HDR)
	@$(GC) $(FLAGS) -o $@ -c $<

all: make_lib $(NAME)

make_lib:
	@echo "$(C_YELLOW)make libft...$(C_END)"
	@make -C $(LIBFTDIR)

$(NAME): $(OBJ) $(HDR) libft/libft.a
	@echo "$(C_YELLOW)make minishell...$(C_END)"
	@$(GC) $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFTDIR) -lft
	@echo "$(C_GREEN)FINISHED!$(C_END)"

clean:
	@echo "$(C_RED)cleaning *.o$(C_END)"
	@make clean -s -C $(LIBFTDIR)
	@rm -f $(OBJ)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

fclean: clean
	@echo "$(C_RED)cleaning executable$(C_END)"
	@make fclean -s -C $(LIBFTDIR)
	@rm -f $(NAME)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

re: fclean all
	@echo "$(C_GREEN)Recompiled!$(C_END)"
