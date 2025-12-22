/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:42:24 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/22 17:28:03 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
* @brief Swap for more 2 nb.
*/
void	swap(t_list **stack)
{
	t_list	*nfirst_node;
	t_list	*third_node;

	if (!(*stack))
		return ;
	nfirst_node = (*stack)->next;
	third_node = nfirst_node->next;
	third_node->prev = *stack;
	(*stack)->prev = nfirst_node;
	(*stack)->next = third_node;
	nfirst_node->next = *stack;
	nfirst_node->prev = NULL;
	*stack = nfirst_node;
}

/**
* @brief Sort 2 numbers.
* @warning Not more 2 numbers.
* @param stack
* @details dfsdfsdfsdfsdfsdf
* @return Nothing.
*/
void	swap_two(t_list **stack)
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
}

void	push(t_list **stack_start, t_list **stack_end)
{
	t_list	*node_push;
	t_list	*nfirst_node;

	if (!(*stack_start))
		return ;
	node_push = *stack_start;
	if (node_push->next == NULL)
		*stack_start = NULL;
	else
	{
		nfirst_node = node_push->next;
		nfirst_node->prev = NULL;
		*stack_start = nfirst_node;
	}
	if (*stack_end)
	{
		node_push->prev = NULL;
		node_push->next = *stack_end;
		(*stack_end)->prev = node_push;
		*stack_end = node_push;
	}
	else
	{
		node_push->prev = NULL;
		node_push->next = NULL;
		*stack_end = node_push;
	}
}

void	rotate(t_list **stack)
{
	t_list	*nfirst_node;
	t_list	*nlast_node;
	t_list	*last_node;

	if (!(*stack))
		return ;
	nfirst_node = (*stack)->next;
	nlast_node = *stack;
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
	lfisrt_node = *stack;
	nfirst_node = ft_lstlast(*stack);
	nlast_node = nfirst_node->prev;
	lfisrt_node->prev = nfirst_node;
	nfirst_node->next = lfisrt_node;
	*stack = nfirst_node;
	nlast_node->next = NULL;
	nfirst_node->prev = NULL;
}
