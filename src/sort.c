/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:07:28 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/22 14:04:14 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	smaller_nb(t_list *node)
{
	int	nb;

	nb = node->content;
	while (node->next != NULL)
	{
		if (node->content < nb)
			nb = node->content;
		node = node->next;
	}
	if (node->content < nb)
		nb = node->content;
	return (nb);
}

void	sort_three(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
	{
		rotate(stack);
		printf("ra\n");
	}
	if ((*stack)->next->content > (*stack)->content
		&& (*stack)->next->content > (*stack)->content
		&& (*stack)->next->content > (*stack)->next->next->content)
	{
		reverse_rotate(stack);
		printf("rra\n");
	}
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->next->content > (*stack)->next->content
		&& (*stack)->next->next->content > (*stack)->content)
	{
		swap(stack);
		printf("sa\n");
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int			node_push;
	t_targets	values;

	push(stack_a, stack_b);
	push(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		node_push = (*stack_a)->content;
		init_values(&values, node_push, *stack_b);
		if (node_push > values.max || node_push < values.min)
			push_setup(values.max, stack_b);
		else if (node_push < values.max)
			push_setup(values.inf, stack_b);
		push(stack_a, stack_b);
		printf("pb\n");
	}
	if (ft_lstsize(*stack_a) <= 2)
		swap_two(stack_a);
	else
		sort_three(stack_a);
	push_setup(values.max, stack_b);
}

