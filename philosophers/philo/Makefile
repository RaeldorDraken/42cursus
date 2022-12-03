# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 14:48:15 by eros-gir          #+#    #+#              #
#    Updated: 2022/12/03 12:05:48 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = ./src/philo_main.c ./src/philo_utils.c ./src/philo_print.c

HDR = ./incl/philolib.h

OBJ = $(SRC:.c=.o)

GC = gcc
FLAGS = -g -Wall -Wextra -Werror

%.o: %.c $(HDR)
	$(GC) $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	$(GC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
