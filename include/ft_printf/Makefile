CC= cc
CFLAGS= -Wall -Wextra -Werror -g
HEADER=ft_printf.h

NAME=libftprintf.a

BUILD_DIR=obj/
INCLUDE= include/
SRC_DIR=src/

SRC= ft_printf.c \
	print_function.c

OBJ= $(SRC:%.c=$(BUILD_DIR)%.o)
OBJ_DIR= $(sort $(shell dirname $(OBJ)))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "ft_printf link"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
