/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truck_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:41:20 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/29 10:43:26 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
* @brief calcul of the cost required to place each nb at the top of the stack
*/
void	top_cost(t_list **stack)
{
	int		index;
	int		total_node;
	t_list	*inode;

	total_node = ft_lstsize(*stack);
	inode = *stack;
	while (inode)
	{
		index = ft_lstnsize(*stack, inode->content);
		if (index <= (total_node / 2))
			inode->top_of_cost = index;
		else
			inode->top_of_cost = total_node - index;
		inode = inode->next;
	}
}

/**
* @brief calcul the total cost for push the nb in the stack_a
* @param stack_b, stack_a
*/
void	push_cost(t_list **stack_b,t_list **stack_a)
{
	t_targets	value;
	t_list		*b;
	t_list		*a;

	b = *stack_b;
	while (b)
	{
		init_values(&value, b->content, *stack_a);
		if (b->content > value.max || b->content < value.min)
			b->target = value.min;
		else
		{
			b->target = value.higher;
			printf("higher -> nb %d\n", b->content);
		}
		a = *stack_a;
		while (a && a->content != b->target)
			a = a->next;
		b->total_cost = b->top_of_cost + a->top_of_cost;
		b = b->next;
	}
}

void	init_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*min_cost;
	t_list	*b;

	while (*stack_b)
	{
		top_cost(stack_b);
		top_cost(stack_a);
		push_cost(stack_b, stack_a);
		b = *stack_b;
		min_cost = b;
		while (b)
		{
			if (b->total_cost < min_cost->total_cost)
				min_cost = b;
			b = b->next;
		}
		while ((*stack_a)->content != min_cost->target
		|| (*stack_b)->content != min_cost->content)
			push_setup(min_cost, stack_a, stack_b);
		push(stack_b, stack_a, 1, 0);
	}
}
