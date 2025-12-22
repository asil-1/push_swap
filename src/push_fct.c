/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:25:13 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/22 18:53:30 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
* @warning Doesn't print "r..\n"
* @todo change namde and opti
*/
void	push_setup(int target, t_list **stack)
{
	while (((*stack)->next != NULL) && ((*stack)->content != target))
	{
		rotate(stack);
		printf("ra\n");
	}
}

/**
* @brief Use push_setup and t_targets for push up the target node in decrease.
* @param starting_stack, final_stack of the value push
* @warning Printf "pb\n"
*/
void	push_to_target_decrease(t_list **stack_start, t_list **stack_end)
{
	int			node_push;
	t_targets	values;

	node_push = (*stack_start)->content;
	init_values(&values, node_push, *stack_end);
	if (node_push > values.max || node_push < values.min)
		push_setup(values.max, stack_end);
	else if (node_push < values.max)
		push_setup(values.lower, stack_end);
	push(stack_start, stack_end);
	printf("pb\n");
}

/**
* @brief Use push_setup and t_targets for push up the target node in increase order.
* @param starting_stack, final_stack of the value push
* @warning Print "pa\n"
*/
void	push_to_target_increase(t_list **stack_start, t_list **stack_end)
{
	int			node_push;
	t_targets	values;

	node_push = (*stack_start)->content;
	init_values(&values, node_push, *stack_end);
	if (node_push > values.max || node_push < values.min)
		push_setup(values.max, stack_end);
	else if (node_push < values.max)
		push_setup(values.higher, stack_end);
	push(stack_start, stack_end);
	printf("pa\n");
}
