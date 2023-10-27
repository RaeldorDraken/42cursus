# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 15:41:23 by eros-gir          #+#    #+#              #
#    Updated: 2023/10/27 11:07:43 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_YELLOW=\033[0;33m
C_END=\033[0m

NAME = intNrecap

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	./srcs/main.cpp \
		./srcs/AMateria.cpp \
		./srcs/Character.cpp \
		./srcs/ICharacter.cpp \
		./srcs/Cure.cpp \
		./srcs/Ice.cpp \
		./srcs/MateriaSource.cpp \
		./srcs/IMateriaSource.cpp
HDRS =	./incl/AMateria.hpp \
		./incl/Character.hpp \
		./incl/ICharacter.hpp \
		./incl/Cure.hpp \
		./incl/Ice.hpp \
		./incl/MateriaSource.hpp \
		./incl/IMateriaSource.hpp

all:$(NAME)

$(NAME): $(SRCS) $(HDRS)
	@echo "$(C_YELLOW)make Interface & recap$(C_END)"
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "$(C_GREEN)Completed...$(C_END)"

clean:
	@echo "$(C_RED)cleaning executable$(C_END)"
	@rm -rf $(NAME)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

fclean:
	@echo "$(C_RED)cleaning executable$(C_END)"
	@rm -rf $(NAME)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

re: fclean all

PHONY: all clean fclean re
