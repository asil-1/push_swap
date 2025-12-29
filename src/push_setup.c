/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:03:50 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/29 10:42:19 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	move_a(t_list **a, t_list *node)
{
	int	index;

	index = ft_lstnsize(*a, node->target);
	if ((*a)->content != node->target)
	{
		if (index <= (ft_lstsize(*a) / 2))
			return (1);
		else
			return (2);
	}
	return (0);
}

static int	move_b(t_list **b, t_list *node)
{
	int	index;

	if (ft_lstsize(*b) < 2)
		return (0);
	index = ft_lstnsize(*b, node->content);
	if ((*b)->content != node->content)
	{
		if (index <= (ft_lstsize(*b) / 2))
			return (1);
		else
			return (2);
	}
	return (0);
}

static void	rotate_a_or_b(t_list **a, t_list **b, t_list *node)
{
	if (move_a(a, node) == 1 && move_b(b, node) == 1)
	{
		rotate(a, 0, 0);
		rotate(b, 0, 0);
		printf("rr\n");
	}
	else if (move_a(a, node) == 1 && move_b(b, node) != 1)
		rotate(a, 1, 0);
	else if (move_a(a, node) != 1 && move_b(b, node) == 1)
		rotate(b, 0, 1);
}

static void	reverse_rotate_a_or_b(t_list **a, t_list **b, t_list *node)
{
	if (move_a(a, node) == 2 && move_b(b, node) == 2)
	{
		reverse_rotate(a, 0, 0);
		reverse_rotate(b, 0, 0);
		printf("rrr\n");
	}
	else if (move_a(a, node) == 2 && move_b(b, node) != 2)
		reverse_rotate(a, 1, 0);
	else if (move_a(a, node) != 2 && move_b(b, node) == 2)
		reverse_rotate(b, 0, 1);
}

/**
* @brief place the target at the top of the stack
*/
void	push_setup(t_list *node, t_list **a, t_list **b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = *a;
	stack_b = *b;
	printf("node target %d\n", node->target);
	printf("content %d\n", (*a)->content);
	if ((stack_a && stack_b)
		&& ((stack_a)->content != node->target
		|| (stack_b)->content != node->content))
	{
		if (move_a(a, node) == 1 || move_b(b, node) == 1)
			rotate_a_or_b(a, b, node);
		if (move_a(a, node) == 2 || move_b(b, node) == 2)
			reverse_rotate_a_or_b(a, b, node);
	}
}
