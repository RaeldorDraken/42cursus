# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 15:41:23 by eros-gir          #+#    #+#              #
#    Updated: 2023/10/27 11:35:46 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_YELLOW=\033[0;33m
C_END=\033[0m

NAME = abstract

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	./srcs/main.cpp \
		./srcs/AAnimal.cpp \
		./srcs/Dog.cpp \
		./srcs/Cat.cpp \
		./srcs/WrongAnimal.cpp \
		./srcs/WrongCat.cpp \
		./srcs/Brain.cpp
HDRS =	./incl/polymorph.h \
		./incl/AAnimal.hpp \
		./incl/Dog.hpp \
		./incl/Cat.hpp \
		./incl/WrongAnimal.hpp \
		./incl/WrongCat.hpp \
		./incl/Brain.hpp

OBJ = $(SRCS:.cpp=.o)
DEP = $(SRCS:.cpp=.d)

all:$(NAME)

$(NAME): $(OBJ) $(HDRS) Makefile
	@echo "$(C_YELLOW)make Abstract class$(C_END)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(C_GREEN)Completed...$(C_END)"

clean:
	@echo "$(C_RED)cleaning obj and dep$(C_END)"
	@rm -rf $(OBJ) $(DEP)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

fclean:
	@echo "$(C_RED)cleaning executable$(C_END)"
	@rm -rf $(NAME) $(OBJ) $(DEP)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

re: fclean all

PHONY: all clean fclean re
