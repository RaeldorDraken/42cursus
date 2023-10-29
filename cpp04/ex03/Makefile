# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 15:41:23 by eros-gir          #+#    #+#              #
#    Updated: 2023/10/29 21:46:59 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_YELLOW=\033[0;33m
C_END=\033[0m

NAME = intNrecap

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address

SRCS =	./srcs/main.cpp \
		./srcs/AMateria.cpp \
		./srcs/Character.cpp \
		./srcs/ICharacter.cpp \
		./srcs/Cure.cpp \
		./srcs/Ice.cpp \
		./srcs/MateriaSource.cpp \
		./srcs/IMateriaSource.cpp \
		./srcs/AMateriaFloor.cpp \
		./srcs/Floor.cpp
HDRS =	./incl/AMateria.hpp \
		./incl/Character.hpp \
		./incl/ICharacter.hpp \
		./incl/Cure.hpp \
		./incl/Ice.hpp \
		./incl/MateriaSource.hpp \
		./incl/IMateriaSource.hpp \
		./incl/AMateriaFloor.hpp \
		./incl/Floor.hpp

OBJ = $(SRCS:.cpp=.o)
DEP = $(SRCS:.cpp=.d)

all:$(NAME)

$(NAME): $(OBJ) $(HDRS) Makefile
	@echo "$(C_YELLOW)make Interface & recap$(C_END)"
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
