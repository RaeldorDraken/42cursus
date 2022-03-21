# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 16:23:21 by eros-gir          #+#    #+#              #
#    Updated: 2022/03/21 12:06:43 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_formats.c ft_tab_args.c ft_tab_args_two.c

SRC2 = ft_printf.o ft_printf_formats.o ft_tab_args.o ft_tab_args_two.o

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(SRC2)

clean:
	make clean -C libft
	/bin/rm -f $(SRC2)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all
