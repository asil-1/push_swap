/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:28:50 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/31 12:35:32 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"
# include <unistd.h>
# include <stdio.h> // a enlever

typedef struct s_target_values
{
	int	max;
	int	min;
	int	lower;
	int	higher;
}	t_targets;

//push_swap.c
int		main(int argc, char **argv);

//parsing.c
char	**parsing(int argc, char **argv);

//init_values.c
int		smaller_nb(t_list *node);
int		greater_nb(t_list *node);
int		init_stack(int argc, char **argv, t_list **stack_a);
void	init_values(t_targets *values, int nb, t_list *stack);

//functions.c
void	swap(t_list **stack, int a, int b);
void	push(t_list **stack_start, t_list **stack_end, int a, int b);
void	formatting(t_list **stack_a);

//functions_two.c
void	rotate(t_list **stack, int a, int b);
void	reverse_rotate(t_list **stack, int a, int b);

//sort.c
void	sort(t_list **stack_a, t_list **stack_b, size_t nb_node);

//push_to_b.c
void	push_to_b(t_list **stack_a, t_list **stack_b);

//push_to_b_set_up.c
void	push_setup(t_list *node, t_list **a, t_list **b);

//push_to_a.c
void	push_to_a(t_list **stack_a, t_list **stack_b);

#endif