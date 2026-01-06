/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:11:31 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/05 20:30:47 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_target(t_list **stack_a, t_list **stack_b)
{
	t_targets	value;
	t_list		*b;

	b = *stack_b;
	while (b)
	{
		init_values(&value, b->content, *stack_a);
		if (b->content > value.max || b->content < value.min)
			b->target = value.min;
		else
			b->target = value.higher;
		b = b->next;
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	index;

	push_target(stack_a, stack_b);
	while ((*stack_a)->content != (*stack_b)->target)
	{
		index = ft_lstnsize(*stack_a, (*stack_b)->target);
		if (index <= ft_lstsize(*stack_a) / 2)
			rotate(stack_a, PRINT_A);
		else
			reverse_rotate(stack_a, PRINT_A);
	}
	push(stack_b, stack_a, PRINT_A);
}
