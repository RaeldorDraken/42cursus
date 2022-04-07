# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 10:39:30 by eros-gir          #+#    #+#              #
#    Updated: 2022/04/07 10:42:52 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c utilities.c check_map.c get_next_line.c
SRC2 = main.o utilities.o check_map.o get_next_line.o

GC = gcc -Wall -Wextra -Werror
AR = ar rcs

MLXDIR = ./minilibx/
LIBFTDIR = ./libft/

OBJS = $(SRC:.c=.o)

.c.o :
	$(GC) -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	cp $(MLXDIR)/libmlx.dylib .
	$(GC) -o $(NAME) $(OBJS) -L $(MLXDIR) -lmlx -L $(LIBFTDIR) -lft -framework OpenGL -framework AppKit

clean:
	make clean -C libft
	make clean -C minilibx
	/bin/rm -f $(SRC2)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)
	/bin/rm -f libmlx.dylib

re: fclean all

bonus: all
