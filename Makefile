#COPMILE_______________________
CC = cc
CFLAGS = $(ALL_INCLUDES) -Wall -Wextra -Werror -g
MAKEFLAGS += --no-print-directory

HEADER = push_swap.h

NAME = push_swap
NAME_BONUS = checker

#INCLUDES______________________

INCLUDE = include/
ALL_INCLUDES = -I $(INCLUDE) -I $(INCLUDE_LIBFT) -I $(INCLUDE_FT_PRINTF)

BUILD_DIR = obj/
BUILD_DIR_BONUS = obj_bonus/
SRC_DIR = src/
SRC_DIR_BONUS = src_bonus/

#LIBFT
INCLUDE_LIBFT = include/libft/
LIBFT = include/libft/libft.a

#FT_PRINTF
INCLUDE_FT_PRINTF = include/ft_printf/
FT_PRINTF = include/ft_printf/libftprintf.a

#SRC___________________________

SRC=main.c \
	parsing.c \
	init_values.c \
	functions.c \
	functions_two.c \
	sort.c \
	push_to_b.c \
	push_to_b_setup.c \
	push_to_a.c

SRC_BONUS=main_bonus.c \
	parsing_bonus.c \
	init_stack_bonus.c \
	functions_bonus.c \
	functions_two_bonus.c \
	cmd_bonus.c \
	get_next_line_bonus.c \
	what_function_bonus.c

#OBJ___________________________

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)
OBJ_DIR = $(sort $(shell dirname $(OBJ)))

OBJ_BONUS= $(SRC_BONUS:%.c=$(BUILD_DIR_BONUS)%.o)
OBJ_DIR_BONUS = $(sort $(shell dirname $(OBJ_BONUS)))

#_________________________________

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "push_swap link"

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "checker link"

$(LIBFT):
	@make -C include/libft

$(FT_PRINTF):
	@make -C include/ft_printf


$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(OBJ_DIR):
	@mkdir -p $@

$(BUILD_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c | $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(OBJ_DIR_BONUS):
	@mkdir -p $@

clean:
	@make -C include/libft/ clean
	@make -C include/ft_printf/ clean
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_DIR_BONUS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	@rm -f $(LIBFT)
	@rm -f $(FT_PRINTF)

re: fclean all

.PHONY: all clean bonus fclean re