/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truck_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:41:20 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/27 19:38:03 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*calcul du cout pour passer mon chiffre target en haut de la stack*/
void	move_to_the_top(t_list **stack)
{
	int		index;
	int		total_node;
	t_list	*inode;

	total_node = ft_lstsize(*stack);
	inode = *stack;
	while (inode)
	{
		index = ft_lstnsize(*stack, inode->content);
		if (index <= (total_node / 2))
			inode->top_of_cost = index;
		else
			inode->top_of_cost = total_node - index;
		inode = inode->next;
	}
}
/*befor this, push all except three */
void	init_cost(t_list **stack_a, t_list **stack_b)
{
	t_list		*inode;
	t_list		*t_node;
	t_targets	value;
	int			target;

	move_to_the_top(stack_b);
	move_to_the_top(stack_a);
	inode = *stack_b;
	while (inode)
	{
		/*find the taregt*/
		init_values(&value, inode->content, *stack_a);
		printf("\n%d\n", inode->content);
		if (inode->content > value.max || inode->content < value.min)
			target = value.min;
		else
			target = value.higher;
		printf("top of cost b %d\n", inode->top_of_cost);
		t_node = *stack_a;
		while (t_node && t_node->content != target)
			t_node = t_node->next;
		printf("target %d\n", target);
		printf("top of cost a %d\n", t_node->top_of_cost);
		inode->total_cost = inode->top_of_cost + t_node->top_of_cost;
		printf("total cost %d\n", inode->total_cost);
		inode = inode->next;
	}
}
