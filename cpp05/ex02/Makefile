# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:40:05 by eros-gir          #+#    #+#              #
#    Updated: 2023/11/24 16:39:51 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_YELLOW=\033[0;33m
C_END=\033[0m

NAME = 28B

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRCS =	./Bureaucrat.cpp \
		./AForm.cpp \
		./PresidentialPardonForm.cpp \
		./RobotomyRequestForm.cpp \
		./ShrubberyCreationForm.cpp \
		./main.cpp
HDRS =	./Bureaucrat.hpp \
		./AForm.hpp \
		./PresidentialPardonForm.hpp \
		./RobotomyRequestForm.hpp \
		./ShrubberyCreationForm.hpp

OBJ = $(SRCS:.cpp=.o)
DEP = $(SRCS:.cpp=.d)

all:$(NAME)

$(NAME): $(OBJ) $(HDRS) Makefile
	@echo "$(C_YELLOW)make 28B$(C_END)"
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
