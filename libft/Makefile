# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:00:26 by eros-gir          #+#    #+#              #
#    Updated: 2022/01/11 11:53:18 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

SRC2 = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(SRC2)
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
