# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:00:26 by eros-gir          #+#    #+#              #
#    Updated: 2022/03/17 12:32:23 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c ft_atoi.c \
ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_bzero.c \
ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c ft_calloc.c \
ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c ft_isalnum.c \
ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c ft_isalpha.c \
ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c ft_isascii.c \
ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c

SRC2 = ft_isdigit.o ft_memset.o ft_strdup.o ft_strncmp.o ft_atoi.o \
ft_isprint.o ft_putchar_fd.o ft_striteri.o ft_strnstr.o ft_bzero.o \
ft_itoa.o ft_putendl_fd.o ft_strjoin.o ft_strrchr.o ft_calloc.o \
ft_memchr.o ft_putnbr_fd.o ft_strlcat.o ft_strtrim.o ft_isalnum.o \
ft_memcmp.o ft_putstr_fd.o ft_strlcpy.o ft_substr.o ft_isalpha.o \
ft_memcpy.o ft_split.o ft_strlen.o ft_tolower.o ft_isascii.o \
ft_memmove.o ft_strchr.o ft_strmapi.o ft_toupper.o

SRCB = ft_lstlast.c	ft_lstmap.c ft_lstnew.c	ft_lstsize.c  ft_lstadd_back.c \
ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c

SRCB2 = ft_lstlast.o ft_lstmap.o ft_lstnew.o ft_lstsize.o ft_lstadd_back.o \
ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(SRC2)
clean:
	/bin/rm -f $(SRC2)

fclean: clean
	/bin/rm -f $(NAME)

bonus:
	gcc -Wall -Wextra -Werror -c $(SRC) $(SRCB)
	ar rc $(NAME) $(SRC2) $(SRCB2)

re: fclean all
