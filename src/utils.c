/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:58:53 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/22 14:01:34 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack_a(t_list	**stack_a, int content)
{
	t_list	*node;

	node = ft_newnode(content);
	ft_lstadd_back(stack_a, node);
}

void	init_values(t_targets *values, int nb, t_list *stack)
{
	int	content;
	t_list	*tmp;


	tmp = stack;
	values->max = stack->content;
	values->min = smaller_nb(stack);
	while (stack->next != NULL)
	{
		content = stack->content;
		if (content > values->max)
			values->max = content;
		if (content >= values->min && content < nb)
			values->min = content;
		stack = stack->next;
	}
	if (content > values->max)
		values->max = content;
	values->inf = values->min;
	values->min = smaller_nb(tmp);
}

/**
* @warning opti ca
*/
void	push_setup(int target, t_list **stack)
{
	while (*stack && ((*stack)->content != target))
	{
		rotate(stack);
		printf("rb\n");
	}
}

void	what_sort(t_list **stack_a, t_list **stack_b, size_t i)
{
	if (i == 2)
	{
		swap_two(stack_a);
		printf("sa\n");
	}
	else if (i == 3)
		sort_three(stack_a);
	else if (i > 3)
		sort(stack_a, stack_b);
}
