/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:07:28 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/27 18:43:46 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
	{
		rotate(stack);
		printf("ra\n");
	}
	if ((*stack)->next->content > (*stack)->content
		&& (*stack)->next->content > (*stack)->content
		&& (*stack)->next->content > (*stack)->next->next->content)
	{
		reverse_rotate(stack);
		printf("rra\n");
	}
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->next->content > (*stack)->next->content
		&& (*stack)->next->next->content > (*stack)->content)
	{
		swap(stack);
		printf("sa\n");
	}
}

void	sort_four_five(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		push(stack_a, stack_b);
		printf("pb\n");
	}
	sort_three(stack_a);
	while(*stack_b)
		push_to_target_increase(stack_b, stack_a);
	push_setup(smaller_nb(*stack_a), stack_a);
}

// void	sort(t_list **stack_a, t_list **stack_b)
// {
// 	t_targets	values;

// 	push(stack_a, stack_b);
// 	push(stack_a, stack_b);
// 	printf("pb\npb\n");
// 	while (ft_lstsize(*stack_a) > 3)
// 	{
// 		push_to_target_decrease(stack_a, stack_b);
// 		printf("pb\n");
// 	}
// 	if (ft_lstsize(*stack_a) <= 2)
// 		swap_two(stack_a);
// 	else
// 		sort_three(stack_a);
// 	init_values(&values, (*stack_a)->content, *stack_b);
// 	push_setup(values.max, stack_b);
// }

void	sort(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		push(stack_a, stack_b);
		printf("pb\n");
	}
	sort_three(stack_a);
	init_cost(stack_a, stack_b);
}

