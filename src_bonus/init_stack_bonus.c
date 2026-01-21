/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:38:56 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/19 19:59:49 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_stack_a(t_list **stack_a, int content)
{
	t_list	*node;

	node = ft_newnode(content);
	ft_lstadd_back(stack_a, node);
}

int	init_stack_bonus(int argc, char **argv, t_list **stack_a)
{
	size_t	nb;
	char	**args;

	nb = 0;
	args = parsing_bonus(argc - 1, argv + 1);
	if (!args)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	while (args[nb])
	{
		init_stack_a(stack_a, ft_atoi(args[nb]));
		free(args[nb]);
		nb++;
	}
	free(args);
	return (nb);
}
