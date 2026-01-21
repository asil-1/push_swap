/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_function_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:20:17 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/21 12:49:58 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	what_swap(char *cmd, t_list **stack_a, t_list **stack_b)
{
	if (cmd[1] == 'a' && cmd[2] == '\n')
	{
		swap_bonus(stack_a);
		return (1);
	}
	if (cmd[1] == 'b' && cmd[2] == '\n')
	{
		swap_bonus(stack_b);
		return (1);
	}
	return (0);
}

int	what_push(char *cmd, t_list **stack_a, t_list **stack_b)
{
	if (cmd[1] == 'a' && cmd[2] == '\n')
	{
		push_bonus(stack_b, stack_a);
		return (1);
	}
	if (cmd[1] == 'b' && cmd[2] == '\n')
	{
		push_bonus(stack_a, stack_b);
		return (1);
	}
	return (0);
}

static int	what_reverse_rotate(char *cmd, t_list **stack_a, t_list **stack_b)
{
	if (cmd[2] == 'a' && cmd[3] == '\n')
	{
		reverse_rotate_bonus(stack_a);
		return (1);
	}
	if (cmd[2] == 'b' && cmd[3] == '\n')
	{
		reverse_rotate_bonus(stack_b);
		return (1);
	}
	if (cmd[2] == 'r' && cmd[3] == '\n')
	{
		reverse_rotate_bonus(stack_a);
		reverse_rotate_bonus(stack_b);
		return (1);
	}
	return (0);
}

int	what_rotate(char *cmd, t_list **stack_a, t_list **stack_b)
{
	if (cmd[1] == 'a' && cmd[2] == '\n')
	{
		rotate_bonus(stack_a);
		return (1);
	}
	if (cmd[1] == 'b' && cmd[2] == '\n')
	{
		rotate_bonus(stack_b);
		return (1);
	}
	if (cmd[1] == 'r')
	{
		if (what_reverse_rotate(cmd, stack_a, stack_b))
			return (1);
		else if (cmd[2] == '\n')
		{
			rotate_bonus(stack_a);
			rotate_bonus(stack_b);
			return (1);
		}
	}
	return (0);
}
