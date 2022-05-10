# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 10:39:30 by eros-gir          #+#    #+#              #
#    Updated: 2022/05/10 13:51:34 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c utilities.c inputs.c check_map.c get_next_line.c check_errors.c
SRC2 = main.o utilities.o inputs.o check_map.o get_next_line.o check_errors.o
SRCB = main.c utilities_bonus.c inputs_bonus.c check_map.c get_next_line.c \
check_errors_bonus.c
SRCB2 = main.o utilities_bonus.o inputs_bonus.o check_map.o get_next_line.o \
check_errors_bonus.o

GC = gcc -Wall -Wextra -Werror
AR = ar rcs

MLXDIR = ./minilibx/
LIBFTDIR = ./libft/

OBJS = $(SRC:.c=.o)

OBJSB = $(SRCB:.c=.o)

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
	/bin/rm -f $(SRC2) $(SRCB2)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)
	/bin/rm -f libmlx.dylib

re: fclean all

bonus: $(OBJSB)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	cp $(MLXDIR)/libmlx.dylib .
	$(GC) -o $(NAME) $(OBJSB) -L $(MLXDIR) -lmlx -L $(LIBFTDIR) -lft -framework OpenGL -framework AppKit

