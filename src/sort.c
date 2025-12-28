/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:07:28 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/28 14:22:56 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_two(t_list **stack)
{
	t_list	*node;

	if ((*stack)->content <= (*stack)->next->content)
		return ;
	node = (*stack)->next;
	(*stack)->prev = node;
	(*stack)->next = NULL;
	node->next = *stack;
	*stack = node;
	node->prev = NULL;
	printf("sa\n");
}

void	what_sort(t_list **stack_a, t_list **stack_b, size_t i)
{
	if (i == 2)
		swap_two(stack_a);
	else if (i == 3)
		sort_three(stack_a);
	// else if (i > 3 && i <= 5)
		// sort_four_five(stack_a, stack_b);
	else if (i > 3)
		sort(stack_a, stack_b);
}

void	sort_three(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
		rotate(stack, 1, 0);
	if ((*stack)->next->content > (*stack)->content
		&& (*stack)->next->content > (*stack)->content
		&& (*stack)->next->content > (*stack)->next->next->content)
		reverse_rotate(stack, 1, 0);
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->next->content > (*stack)->next->content
		&& (*stack)->next->next->content > (*stack)->content)
		swap(stack, 1, 0);
}

void	sort_four_five(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		push(stack_a, stack_b, 0, 1);
	sort_three(stack_a);
	// while(*stack_b)	/** @todo reparer ca */
		// push_to_target_increase(stack_b, stack_a);
	// push_setup(smaller_nb(*stack_a), stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		push(stack_a, stack_b, 0, 1);
	sort_three(stack_a);
	init_cost(stack_a, stack_b);
}

