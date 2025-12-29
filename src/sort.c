/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:07:28 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/29 14:01:46 by ldepenne         ###   ########.fr       */
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
	t_list	*a;
	int		node;
	int		n_node;

	a = *stack_a;
	while (a)
	{
		node = a->content;
		if (a->next != NULL)
			n_node = a->next->content;
		if (node > n_node)
			break ;
		a = a->next;
	}
	if (!a)
		return ;
	if (i == 2)
		swap_two(stack_a);
	else if (i == 3)
		sort_three(stack_a);
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

void	sort(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		push(stack_a, stack_b, 0, 1);
	sort_three(stack_a);
	init_cost(stack_a, stack_b);
}
