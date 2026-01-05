/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:48:32 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/05 19:09:42 by ldepenne         ###   ########.fr       */
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

void	swap(t_list **stack, int a, int b)
{
	t_list	*nfirst_node;
	t_list	*third_node;

	if (!(*stack))
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
	if (a && !b)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
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
void	push(t_list **stack_start, t_list **stack_end, int a, int b)
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
	if (a && !b)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	formatting(t_list **stack_a)
{
	int	min;
	int	index;

	min = smaller_nb(*stack_a);
	while ((*stack_a)->content != min)
	{
		index = ft_lstnsize(*stack_a, min);
		if (index <= ft_lstsize(*stack_a) / 2)
			rotate(stack_a, 1, 0);
		else
			reverse_rotate(stack_a, 1, 0);
	}
}
