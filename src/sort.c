/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:41:17 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/05 12:56:10 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_sort(t_list **stack_a)
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
		return (0);
	return (1);
}

static void	sort_three(t_list **stack)
{
	t_list	*s;
	int		node1;
	int		node2;
	int		node3;

	s = *stack;
	node1 = s->content;
	node2 = s->next->content;
	node3 = s->next->next->content;
	if (node1 > node2 && node1 > node3)
		rotate(stack, 1, 0);
	if (node2 > node1 && node2 > node1 && node2 > node3)
		reverse_rotate(stack, 1, 0);
	if (node1 > node2 && node3 > node2 && node3 > node1)
		swap(stack, 1, 0);
	if (is_sort(stack))
		sort_three(stack);
}

static void	turk_sort(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		push_to_a(stack_a, stack_b);
	formatting(stack_a);
}

void	sort(t_list **stack_a, t_list **stack_b, size_t nb_node)
{
	if (!is_sort(stack_a))
		return ;
	if (nb_node == 2)
		swap(stack_a, 1, 0);
	else if (nb_node == 3)
		sort_three(stack_a);
	else if (nb_node > 3)
		turk_sort(stack_a, stack_b);
}
