/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:29:45 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/05 20:39:42 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	move_a(t_list **a, t_list *node)
{
	int	index;

	index = ft_lstnsize(*a, node->content);
	if ((*a)->content != node->content)
	{
		if (index <= (ft_lstsize(*a) / 2))
			return (ROTATE);
		else
			return (R_ROTATE);
	}
	return (NO_MOVE);
}

static int	move_b(t_list **b, t_list *node)
{
	int	index;

	index = ft_lstnsize(*b, node->target);
	if ((*b)->content != node->target)
	{
		if (index <= (ft_lstsize(*b) / 2))
			return (ROTATE);
		else
			return (R_ROTATE);
	}
	return (NO_MOVE);
}

static void	rotate_a_or_b(t_list **a, t_list **b, t_list *node)
{
	if (move_a(a, node) == ROTATE && move_b(b, node) == ROTATE)
	{
		rotate(a, NO_PRINT);
		rotate(b, PRINT_R);
	}
	else if (move_a(a, node) == ROTATE)
		rotate(a, PRINT_A);
	else if (move_b(b, node) == ROTATE)
		rotate(b, PRINT_B);
}

static void	reverse_rotate_a_or_b(t_list **a, t_list **b, t_list *node)
{
	if (move_a(a, node) == R_ROTATE && move_b(b, node) == R_ROTATE)
	{
		reverse_rotate(a, NO_PRINT);
		reverse_rotate(b, PRINT_R);
	}
	else if (move_a(a, node) == R_ROTATE)
		reverse_rotate(a, PRINT_A);
	else if (move_b(b, node) == R_ROTATE)
		reverse_rotate(b, PRINT_B);
}

/**
* @brief place the target at the top of the stack
*/
void	push_setup(t_list *node, t_list **a, t_list **b)
{
	if (move_a(a, node) == ROTATE || move_b(b, node) == ROTATE)
		rotate_a_or_b(a, b, node);
	if (move_a(a, node) == R_ROTATE || move_b(b, node) == R_ROTATE)
		reverse_rotate_a_or_b(a, b, node);
}
