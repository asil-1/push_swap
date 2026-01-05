CC=cc
CFLAGS= -I $(INCLUDE) -I $(INCLUDE_LIBFT) -I $(INCLUDE_FT_PRINTF) -Wall -Wextra -Werror -MMD -MP -g
MAKEFLAGS+= --no-print-directory
HEADER=push_swap.h
NAME=push_swap

BUILD_DIR=obj/
SRC_DIR=src/
INCLUDE=include/

#LIBFT
INCLUDE_LIBFT=include/libft/
LIBFT=include/libft/libft.a

#FT_PRINTF
INCLUDE_FT_PRINTF=include/ft_printf/
FT_PRINTF=include/ft_printf/libftprintf.a

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

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $^ -o $@
	@echo "push_swap link"

$(LIBFT):
	@make -C include/libft

$(FT_PRINTF):
	@make -C include/ft_printf

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@make -C include/libft/ clean
	@make -C include/ft_printf/ clean
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)