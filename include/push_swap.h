/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:28:50 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/21 12:20:04 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"
# include "ft_printf/include/ft_printf.h"
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef enum e_print
{
	NO_PRINT,
	PRINT_A,
	PRINT_B,
	PRINT_R
}	t_print;

typedef enum e_move
{
	NO_MOVE,
	ROTATE,
	R_ROTATE
}	t_move;

typedef struct s_target_values
{
	int	max;
	int	min;
	int	lower;
	int	higher;
}	t_targets;

/*src*/

//parsing.c
char	**parsing(int argc, char **argv);

//init_values.c
int		smaller_nb(t_list *node);
int		greater_nb(t_list *node);
int		init_stack(int argc, char **argv, t_list **stack_a);
void	init_values(t_targets *values, int nb, t_list *stack);

//functions.c
void	swap(t_list **stack, t_print print);
void	push(t_list **stack_start, t_list **stack_end, t_print print);
void	formatting(t_list **stack_a);

//functions_two.c
void	rotate(t_list **stack, t_print print);
void	reverse_rotate(t_list **stack, t_print print);
void	free_split(char **args);

//sort.c
void	sort(t_list **stack_a, t_list **stack_b, size_t nb_node);

//push_to_b.c
void	push_to_b(t_list **stack_a, t_list **stack_b);

//push_to_b_set_up.c
void	push_setup(t_list *node, t_list **a, t_list **b);

//push_to_a.c
void	push_to_a(t_list **stack_a, t_list **stack_b);

/*src_bonus*/

//parsing_bonus.c
char	**parsing_bonus(int argc, char **argv);

//init_stack_bonus.c
int		init_stack_bonus(int argc, char **argv, t_list **stack_a);

//functions_bonus.c
void	swap_bonus(t_list **stack);
void	push_bonus(t_list **stack_start, t_list **stack_end);

//functions_two.c
void	rotate_bonus(t_list **stack);
void	reverse_rotate_bonus(t_list **stack);
void	free_split_bonus(char **args);

//cmd_bonus.c
int		cmd_bonus(t_list **stack_a, t_list **stack_b);
int		is_sort_bonus(t_list **stack_a);

//what_function_bonus.c
int	what_swap(char *cmd, t_list **stack_a, t_list **stack_b);
int	what_push(char *cmd, t_list **stack_a, t_list **stack_b);
int	what_rotate(char *cmd, t_list **stack_a, t_list **stack_b);

//get_next_line_bonus.c
char	*get_next_line(int fd);

#endif