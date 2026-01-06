/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:58:46 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/05 20:31:21 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	above(t_list **stack_a, t_list **stack_b, t_list *a)
{
	int	size_a;
	int	size_b;
	int	pos_a;
	int	pos_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	pos_a = ft_lstnsize(*stack_a, a->content);
	pos_b = ft_lstnsize(*stack_b, a->target);
	if (pos_a <= (size_a / 2) && pos_b <= (size_b / 2))
	{
		if (pos_a > pos_b)
			a->total_cost = pos_a;
		else
			a->total_cost = pos_b;
	}
	else if (pos_a <= (size_a / 2))
		a->total_cost = pos_a;
	else if (pos_b <= (size_b / 2))
		a->total_cost = pos_b;
}

static void	below(t_list **stack_a, t_list **stack_b, t_list *a)
{
	int	size_a;
	int	size_b;
	int	pos_a;
	int	pos_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	pos_a = ft_lstnsize(*stack_a, a->content);
	pos_b = ft_lstnsize(*stack_b, a->target);
	if (pos_a > (size_a / 2) && pos_b > (size_b / 2))
	{
		if ((size_a - pos_a) > (size_b - pos_b))
			a->total_cost = size_a - pos_a;
		else
			a->total_cost = size_b - pos_b;
	}
	else if (pos_a > (size_a / 2))
		a->total_cost += size_a - pos_a;
	else if (pos_b > (size_b / 2))
		a->total_cost += size_b - pos_b;
}

static void	total_cost(t_list **stack_a, t_list **stack_b)
{
	t_targets	value;
	t_list		*a;

	a = *stack_a;
	a->total_cost = 0;
	while (a)
	{
		a->total_cost = 0;
		init_values(&value, a->content, *stack_b);
		if (a->content > value.max || a->content < value.min)
			a->target = value.max;
		else
			a->target = value.lower;
		above(stack_a, stack_b, a);
		below(stack_a, stack_b, a);
		a = a->next;
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*min_cost;
	t_list	*a;

	if (!stack_b || ft_lstsize(*stack_b) < 2)
	{
		push(stack_a, stack_b, PRINT_B);
		return ;
	}
	total_cost(stack_a, stack_b);
	a = *stack_a;
	min_cost = a;
	while (a)
	{
		if (a->total_cost < min_cost->total_cost)
			min_cost = a;
		a = a->next;
	}
	while ((*stack_a)->content != min_cost->content
		|| (*stack_b)->content != min_cost->target)
		push_setup(min_cost, stack_a, stack_b);
	push(stack_a, stack_b, PRINT_B);
}
