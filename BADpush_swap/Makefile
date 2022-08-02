LIBS = libft/libft.a

NAME = push_swap
NAME_BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

SRC = push.c\
	  check_input.c\
	  p_ops.c s_ops.c r_ops.c rr_ops.c\
	  logical.c logical_utils.c logical_utils2.c\
	  save_ops.c check_ops.c\
	  debug.c\
	  s_utils.c v_utils.c i_utils.c

SRC_MANDATORY = $(SRC) main_push.c 
SRC_BONUS = $(SRC) checker.c main_checker.c 

OBJS := $(SRC_MANDATORY:.c=.o)
OBJS_BONUS := $(SRC_BONUS:.c=.o)

PATHS = $(dir $(LIBS))

HEADS = push.h


INCLUDES := $(addprefix -I, $(PATHS))

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

all:  libs $(NAME)

libs:
	$(MAKE) -C $(PATHS)  


$(NAME): $(LIBS) $(OBJS) push.h
	$(CC) $(CFLAGS) $(INCLUDES) -L$(PATHS) -lft $(OBJS) -o $(NAME) 

bonus: libs $(NAME_BONUS) 

$(NAME_BONUS): $(LIBS) $(OBJS_BONUS) push.h
	$(CC) $(CFLAGS) $(INCLUDES) -L$(PATHS) -lft  $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	$(MAKE) clean -C $(PATHS)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS) 	

fclean: clean
	$(MAKE) fclean -C $(PATHS)
	$(RM) ${NAME} 
	$(RM) $(NAME_BONUS)

re: fclean 
	$(MAKE)

.PHONY: all clean fclean re
