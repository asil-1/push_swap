/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:48:32 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/21 13:36:32 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_two(t_list **stack)
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

void	swap_bonus(t_list **stack)
{
	t_list	*nfirst_node;
	t_list	*third_node;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	if ((*stack)->next->next == NULL)
		swap_two(stack);
	else
	{
		nfirst_node = (*stack)->next;
		third_node = nfirst_node->next;
		third_node->prev = *stack;
		(*stack)->prev = nfirst_node;
		(*stack)->next = third_node;
		nfirst_node->next = *stack;
		nfirst_node->prev = NULL;
		*stack = nfirst_node;
	}
}

static void	end_of_stack(t_list *node_push, t_list **stack_end)
{
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

/**
* @brief from stack_start to stack_end
* @param print_a, print_b or
*/
void	push_bonus(t_list **stack_start, t_list **stack_end)
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
	end_of_stack(node_push, stack_end);
}
