/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:56:07 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/05 19:13:14 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_list **stack, int a, int b)
{
	t_list	*nfirst_node;
	t_list	*nlast_node;
	t_list	*last_node;

	if (!(*stack))
		return ;
	nfirst_node = (*stack)->next;
	nlast_node = *stack;
	last_node = ft_lstlast(*stack);
	last_node->next = nlast_node;
	nlast_node->prev = last_node;
	nlast_node->next = NULL;
	*stack = nfirst_node;
	(*stack)->prev = NULL;
	if (a && !b)
		ft_printf("ra\n");
	else if (!a && b)
		ft_printf("rb\n");
}

void	reverse_rotate(t_list **stack, int a, int b)
{
	t_list	*nfirst_node;
	t_list	*nlast_node;
	t_list	*lfisrt_node;

	if (!(*stack))
		return ;
	lfisrt_node = *stack;
	nfirst_node = ft_lstlast(*stack);
	nlast_node = nfirst_node->prev;
	lfisrt_node->prev = nfirst_node;
	nfirst_node->next = lfisrt_node;
	*stack = nfirst_node;
	nlast_node->next = NULL;
	nfirst_node->prev = NULL;
	if (a && !b)
		ft_printf("rra\n");
	else if (!a && b)
		ft_printf("rrb\n");
}
