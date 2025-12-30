/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:07:28 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/30 13:10:45 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_two(t_list **stack)
{
	t_list	*node;

	if ((*stack)->content < (*stack)->next->content)
		return ;
	node = (*stack)->next;
	(*stack)->prev = node;
	(*stack)->next = NULL;
	node->next = *stack;
	*stack = node;
	node->prev = NULL;
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

void	what_sort(t_list **stack_a, t_list **stack_b, size_t nb_node)
{
	t_list	*a;
	int		node;
	int		next_node;

	a = *stack_a;
	while (a)
	{
		node = a->content;
		if (a->next != NULL)
			next_node = a->next->content;
		if (node > next_node)
			break ;
		a = a->next;
	}
	if (!a)
		return ;
	if (nb_node == 2)
		swap(stack_a, 1, 0);
	else if (nb_node == 3)
		sort_three(stack_a);
	else if (nb_node > 3)
		sort(stack_a, stack_b);
}
