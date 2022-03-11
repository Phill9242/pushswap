.PHONY: all clean fclean re

CC = gcc

CFLAGS = -g

NAME = push_swap
SRC_DIR = srcs
OBJ_DIR = objs
HEADER = headers/push_swap.h
RM = rm -f

SRC_FILES = check_arg.c \
			convert_argv.c \
			convert_to_positive.c \
			main.c \
			min_sort.c \
			operations.c \
			radix.c \
			stack_check.c \
			sort_five.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:
	make fclean && make all

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
