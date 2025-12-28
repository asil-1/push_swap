/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:58:53 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/28 16:05:22 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	init_stack_a(t_list	**stack_a, int content)
{
	t_list	*node;

	node = ft_newnode(content);
	ft_lstadd_back(stack_a, node);
}

/**
* @brief define max and min values to the t_list *stack.
*	And higher than the t_targets *value.
* @param value_to_be_initialised, compared_to_this_nb, in_this_stack
*/
void	init_values(t_targets *values, int nb, t_list *stack)
{
	int	content;
	t_list	*tmp;

	tmp = stack;
	values->min = smaller_nb(stack);
	values->max = greater_nb(stack);
	values->higher = values->max;
	while (stack)
	{
		content = stack->content;
		if (content <= values->higher && content > nb)
			values->higher = content;
		stack = stack->next;
	}
}
