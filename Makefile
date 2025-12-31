CC=cc
CFLAGS= -I $(INCLUDE) -I $(INCLUDE_LIBFT) -Wall -Wextra -Werror -MMD -MP -g
MAKEFLAGS+= --no-print-directory
HEADER=push_swap.h
NAME=push_swap

BUILD_DIR=obj/
INCLUDE_LIBFT=include/libft/
INCLUDE=include/
SRC_DIR=src/
LIBFT=include/libft/libft.a

SRC= push_swap.c \
	parsing.c \
	init_values.c \
	functions.c \
	functions_two.c \
	sort.c \
	push_to_b.c \
	push_to_b_setup.c \
	push_to_a.c

OBJ= $(SRC:%.c=$(BUILD_DIR)%.o)
DEPS= $(SRC:%.c=$(BUILD_DIR)%.d)
OBJ_DIR= $(sort $(shell dirname $(OBJ)))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $@
	@echo "push_swap link"

$(LIBFT):
	@make -C include/libft

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@make -C include/libft/ clean
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)