/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:28:50 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/29 13:53:01 by ldepenne         ###   ########.fr       */
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
	int	higher;
}	t_targets;

//push_swap.c
int		main(int argc, char **argv);

//parsing.c
char	**parsing(int argc, char **argv);

//operations.c
void	swap(t_list **stack, int a, int b);
void	push(t_list **stack_a, t_list **stack_b, int a, int b);
void	rotate(t_list **stack, int a, int b);
void	reverse_rotate(t_list **stack, int a, int b);

//sort.c
void	what_sort(t_list **stack_a, t_list **stack_b, size_t i);
void	sort_three(t_list **stack);
// void	sort_four_five(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);

//truk_algo.c
void	init_cost(t_list **stack_a, t_list **stack_b);
void	top_cost(t_list **stack);
void	push_cost(t_list **stack_b,t_list **stack_a);

//utils.c
int		smaller_nb(t_list *node);
int		greater_nb(t_list *node);
void	init_stack_a(t_list **stack_a, int content);
void	init_values(t_targets *values, int nb, t_list *stack);

//push_setup.c
void	push_setup(t_list *node, t_list **a, t_list **b);

#endif