/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:28:50 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/22 18:25:55 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"
# include <unistd.h>
# include <stdio.h> // a enlever

//push_swap.c
void	what_sort(t_list **stack_a, t_list **stack_b, size_t i);
int		main(int argc, char **argv);

//parsing.c
char	**parsing(int argc, char **argv);

//utils.c
void	swap(t_list **stack);
void	swap_two(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b); /* @warning function too long*/
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

typedef struct s_target_values
{
	int	max;
	int	min;
	int	lower;
	int	higher;
}	t_targets;

//init_function.c
int		smaller_nb(t_list *node);
int		greater_nb(t_list *node);
void	init_stack_a(t_list	**stack_a, int content);
void	init_values(t_targets *values, int nb, t_list *stack);

//push_functions.c
void	push_setup(int target, t_list **stack); /*change name, place le traget en au de la pile*/
void	push_to_target_decrease(t_list **stack_start, t_list **stack_end);
void	push_to_target_increase(t_list **stack_start, t_list **stack_end);

//sort.c
void	sort_three(t_list **stack);
void	sort_four_five(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);

#endif