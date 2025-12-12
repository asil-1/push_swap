/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:42:24 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/12 14:49:50 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack_a(t_list	**stack_a, int content)
{
	t_list	*node;

	node = ft_newnode(content);
	ft_lstadd_back(stack_a, node);
}

void	swap(t_list **stack)
{
	t_list	*node;

	if (!(*stack))
		return ;
	node = (*stack)->next;
	(*stack)->prev = node;
	(*stack)->next = node->next;
	node->next = *stack;
	node->prev = NULL;
	*stack = node;
}

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_b;
	t_list	*node_a;

	if (!(*stack_a))
		return ;
	node_b = (*stack_a);
	*stack_b = node_b;
	node_a = (*stack_a)->next;
	*stack_a = node_a;
	node_b->next = NULL;
	node_a->prev = NULL;
}

void	rotate(t_list **stack)
{
	t_list	*nfirst_node;
	t_list	*nlast_node;
	t_list	*last_node;

	if (!(*stack))
		return ;
	nfirst_node = (*stack)->next;
	nlast_node = (*stack);
	last_node = ft_lstlast(*stack);
	last_node->next = nlast_node;
	nlast_node->prev = last_node;
	nlast_node->next = NULL;
	*stack = nfirst_node;
	(*stack)->prev = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*nfirst_node;
	t_list	*nlast_node;
	t_list	*lfisrt_node;

	if (!(*stack))
		return ;
	lfisrt_node = (*stack);
	nfirst_node = ft_lstlast(*stack);
	nlast_node = nfirst_node->prev;
	lfisrt_node->prev = nfirst_node;
	nfirst_node->next = lfisrt_node;
	*stack = nfirst_node;
	nlast_node->next = NULL;
	nfirst_node->prev = NULL;
}
