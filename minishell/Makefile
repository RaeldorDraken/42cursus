# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 14:48:15 by eros-gir          #+#    #+#              #
#    Updated: 2023/01/30 10:24:24 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./src/ms_main.c

HDR = ./incl/mslib.h ./libft/libft.h

LIBFTDIR = ./libft/

OBJ = $(SRC:.c=.o)

GC = gcc
FLAGS = -g -Wall -Wextra -Werror

%.o: %.c $(HDR)
	$(GC) $(FLAGS) -o $@ -c $<

all: make_lib $(NAME)

make_lib:
	make -C $(LIBFTDIR)

$(NAME): $(OBJ) $(HDR) libft/libft.a
	$(GC) $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFTDIR) -lft

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all
