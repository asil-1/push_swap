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
	init_fct.c \
	push_fct.c \
	utils.c \
	sort.c

OBJ= $(SRC:%.c=$(BUILD_DIR)%.o)
DEPS= $(SRC:%.c=$(BUILD_DIR)%.d)
OBJ_DIR= $(sort $(shell dirname $(OBJ)))

# SRC_BONUS=

# OBJ_BONUS= $(SRC_BONUS:%.c=$(BUILD_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $@
	@echo "push_swap link"

$(LIBFT):
	@make -C include/libft

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

# bonus: $(NAME) $(OBJ_BONUS)
# 	@ar rcs $(NAME) $(OBJ_BONUS)
# 	@echo "push_swap_bonus link"
# 	touch bonus

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@make -C include/libft/ clean
	rm -rf $(BUILD_DIR) bonus

fclean: clean
	rm -rf $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)