CC=cc
CFLAGS=-Wall -Wextra -Werror -g
MAKEFLAGS+= --no-print-directory
HEADER=push_swap.h
NAME=push_swap

BUILD_DIR=obj/
LIBFT=libft/libft.a

SRC= push_swap.c \
	parsing.c \

OBJ= $(SRC:%.c=$(BUILD_DIR)%.o)
OBJ_DIR= $(sort $(shell dirname $(OBJ)))

# SRC_BONUS=

OBJ_BONUS= $(SRC_BONUS:%.c=$(BUILD_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "push_swap link"

$(LIBFT):
	@make -C libft/

$(BUILD_DIR)%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

bonus: $(NAME) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ_BONUS)
	@echo "push_swap_bonus link"
	touch bonus

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf $(BUILD_DIR) bonus
	@make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	@rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re