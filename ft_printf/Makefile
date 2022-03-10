# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 16:23:21 by eros-gir          #+#    #+#              #
#    Updated: 2022/03/10 17:07:10 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c

SRC2 = *.o

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(SRC2)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)
