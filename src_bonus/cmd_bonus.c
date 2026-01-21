/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:15:02 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/21 12:39:20 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	what_cmd(char *cmd, t_list **stack_a, t_list **stack_b)
{
	if (cmd[0] == 's')
	{
		if (!what_swap(cmd, stack_a, stack_b))
			return (0);
	}
	else if (cmd[0] == 'p')
	{
		if (!what_push(cmd, stack_a, stack_b))
			return (0);
	}
	else if (cmd[0] == 'r')
	{
		if (!what_rotate(cmd, stack_a, stack_b))
			return (0);
	}
	return (1);
}

int	cmd_bonus(t_list **stack_a, t_list **stack_b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (!what_cmd(cmd, stack_a, stack_b))
			return (0);
		free(cmd);
		cmd = get_next_line(0);
	}
	return (1);
}

int	is_sort_bonus(t_list **stack_a)
{
	t_list	*a;
	int		node;
	int		next_node;

	a = *stack_a;
	while (a)
	{
		node = a->content;
		if (a->next != NULL)
		{
			next_node = a->next->content;
			if (node > next_node)
				break ;
		}
		a = a->next;
	}
	if (a)
		return (0);
	return (1);
}
