/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:38:56 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/08 13:25:04 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_stack_a(t_list **stack_a, int content)
{
	t_list	*node;

	node = ft_newnode(content);
	ft_lstadd_back(stack_a, node);
}

int	init_stack(int argc, char **argv, t_list **stack_a)
{
	size_t	nb;
	char	**args;

	nb = 0;
	args = parsing(argc - 1, argv + 1);
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

int	smaller_nb(t_list *node)
{
	int	nb;

	nb = node->content;
	while (node->next != NULL)
	{
		if (node->content < nb)
			nb = node->content;
		node = node->next;
	}
	if (node->content < nb)
		nb = node->content;
	return (nb);
}

int	greater_nb(t_list *node)
{
	int	nb;

	nb = node->content;
	while (node->next != NULL)
	{
		if (node->content > nb)
			nb = node->content;
		node = node->next;
	}
	if (node->content > nb)
		nb = node->content;
	return (nb);
}

/**
* @brief define max and min values to the t_list *stack.
*	And higher than the t_targets *value.
* @param value_to_be_initialised, compared_to_this_nb, in_this_stack
*/
void	init_values(t_targets *values, int nb, t_list *stack)
{
	int	content;

	values->min = smaller_nb(stack);
	values->max = greater_nb(stack);
	values->lower = values->min;
	values->higher = values->max;
	while (stack)
	{
		content = stack->content;
		if (content <= values->higher && content > nb)
			values->higher = content;
		if (content >= values->lower && content < nb)
			values->lower = content;
		stack = stack->next;
	}
}
