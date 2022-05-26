# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 09:31:50 by eros-gir          #+#    #+#              #
#    Updated: 2022/05/26 10:57:51 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./src/main.c ./src/utilities.c ./src/errors.c
HDR = ./src/pipexlib.h ./libft/libft.h

LIBFTDIR = ./libft/

OBJ = $(SRC:.c=.o)

GC = gcc -Wall -Wextra -Werror

.c.o :
	$(GC) -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	make -C $(LIBFTDIR)
	$(GC) -o $(NAME) $(OBJ) -L $(LIBFTDIR) -lft

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all
