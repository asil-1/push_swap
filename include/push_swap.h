/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:28:50 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/22 13:58:00 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"
# include <unistd.h>
# include <stdio.h> // a enlever

//push_swap.c
int		main(int argc, char **argv);

//parsing.c
char	**parsing(int argc, char **argv);

//functions.c
void	swap(t_list **stack);
void	swap_two(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

typedef struct s_target_values
{
	int	max;
	int	min;
	int inf;
}	t_targets;

//utils.c
void	init_stack_a(t_list	**stack_a, int content);
void	init_values(t_targets *values, int nb, t_list *stack);
void	push_setup(int target, t_list **stack);
void	what_sort(t_list **stack_a, t_list **stack_b, size_t i);

//sort.c
int		smaller_nb(t_list *node);
void	sort_three(t_list **stack);
void	sort(t_list **stack_a, t_list **stack_b);

#endif