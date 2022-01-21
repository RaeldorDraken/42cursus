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

SRC = ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c ft_atoi.c \
ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c maintest.c \
ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c \
ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c

SRC2 = *.o

SRCB = *.c 

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(SRC2)
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

bonus:
	gcc -Wall -Wextra -Werror -c $(SRC) $(SRCB)
	ar rc $(NAME) $(SRC2)

re: fclean all
