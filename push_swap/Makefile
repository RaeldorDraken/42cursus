# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 14:48:15 by eros-gir          #+#    #+#              #
#    Updated: 2022/11/05 16:04:37 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ./src/main.c ./src/swaps1.c ./src/swaps2.c ./src/swaps3.c ./src/swaps4.c \
./src/cases.c ./src/algorithmic.c ./src/setters.c ./src/algorithmic2.c \
./src/radix.c

HDR = ./incl/pslib.h ./libft/libft.h

LIBFTDIR = ./libft/

OBJ = $(SRC:.c=.o)

GC = gcc
FLAGS = -g -Wall -Wextra -Werror

.c.o :
	$(GC) $(FLAGS) -o $@ -c $?

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
