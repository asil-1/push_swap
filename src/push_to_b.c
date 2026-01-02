/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:58:46 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/02 10:24:46 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	top_cost(t_list **stack)
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

// void	opti_push_cost(t_list *b, t_list *a, t_list **stack_b, t_list **stack_a)
// {
// 	int	i;

// 	i = 0;
// 	while ((ft_lstnsize(*stack_b, b->content) <= ((ft_lstsize(*stack_b)- i) /2))
// 		&& (ft_lstnsize(*stack_a, a->content) <= ((ft_lstsize(*stack_a)- i) /2)))
// 	{
// 		a->total_cost--;
// 		i++;
// 	}
// }

static void	push_cost(t_list **stack_a, t_list **stack_b)
{
	t_targets	value;
	t_list		*a;
	t_list		*b;

	a = *stack_a;
	while (a)
	{
		init_values(&value, a->content, *stack_b);
		if (a->content > value.max || a->content < value.min)
			a->target = value.max;
		else
			a->target = value.lower;
		b = *stack_b;
		while (b && b->content != a->target)
			b = b->next;
		a->total_cost = a->top_of_cost + b->top_of_cost;
		// printf("%d\n", a->content);
		// printf("top a %d top b %d total %d", a->top_of_cost, b->top_of_cost, a->total_cost);
		// opti_push_cost(b, a, stack_b, stack_a);
		a = a->next;
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	// t_list	*min_cost;
	// t_list	*a;

	if (!stack_b || ft_lstsize(*stack_b) < 2)
	{
		push(stack_a, stack_b, 0, 1);
		return ;
	}
	top_cost(stack_a);
	top_cost(stack_b);
	push_cost(stack_a, stack_b);
	// a = *stack_a;
	// min_cost = a;
	// while (a)
	// {
	// 	if (a->total_cost < min_cost->total_cost)
	// 		min_cost = a;
	// 	a = a->next;
	// }
	// while ((*stack_a)->content != min_cost->content
		// || (*stack_b)->content != min_cost->target)
	while ((*stack_b)->content != (*stack_a)->target)
		push_setup((*stack_a), stack_a, stack_b);
	push(stack_a, stack_b, 0, 1);
}
