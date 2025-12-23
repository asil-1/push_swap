/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truck_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:41:20 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/23 16:37:39 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*calcul du cout pour passer mon chiffre target en haut de la stack*/
void	move_to_the_top(t_list **stack)
{
	int	index;
	int	total_node;
	t_list	*tmp;

	total_node = ft_lstsize(*stack);
	tmp = *stack;
	while (*stack)
	{
		index = ft_lstnsize(tmp, (*stack)->content);
		if (index <= (total_node / 2))
			(*stack)->top_of_cost = index;
		else
			(*stack)->top_of_cost = total_node - index;
		*stack = (*stack)->next;
	}
}
/*befor this, push all except three */
void	init_cost(t_list **stack_a, t_list **stack_b)
{
	t_targets	value;
	int			target;

	move_to_the_top(stack_b);
	move_to_the_top(stack_a);
	
	while ((*stack_b)->next != NULL)
	{
		init_values(&value, (*stack_b)->content, *stack_a);
		printf("higher value %d\n", value.higher);
		if ((*stack_b)->content > value.max || (*stack_b)->content < value.min)
			target = value.max;
		else if ((*stack_b)->content < value.max)
			target = value.higher;
		while (*stack_a && ((*stack_a)->content != target))
			*stack_a = (*stack_a)->next;
		(*stack_b)->total_cost = (*stack_b)->top_of_cost + (*stack_a)->top_of_cost;
		printf("total cost %d\n", (*stack_b)->total_cost);
		*stack_b = (*stack_b)->next;
	}
}
