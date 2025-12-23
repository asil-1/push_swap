/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truck_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:41:20 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/23 10:11:50 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*calcul du cout pour passer mon chiffre target en haut de la stack*/
int	move_to_the_top(int nb, t_list **stack)
{
	int	index;
	int	total_node;

	total_node = ft_lstsize(*stack);
	while (*stack)
	{
		index = ft_lstnsize(*stack, (*stack)->content);
		if (index <= (total_node / 2))
			(*stack)->top_of_cost = index;
		else
			(*stack)->top_of_cost = total_node - index;
		printf("content %d -> top of cost %d\n", (*stack)->content, (*stack)->top_of_cost);
		*stack = (*stack)->next;
	}
}

void	init_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;

	b = *stack_b;
	while (b)
	{
		b->top_of_cost = move_to_the_top(b->content, stack_b);
		b = b->next;
	}
}
