/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:56:07 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/21 13:37:59 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_list **stack, t_print print)
{
	t_list	*nfirst_node;
	t_list	*nlast_node;
	t_list	*last_node;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	nfirst_node = (*stack)->next;
	nlast_node = *stack;
	last_node = ft_lstlast(*stack);
	last_node->next = nlast_node;
	nlast_node->prev = last_node;
	nlast_node->next = NULL;
	*stack = nfirst_node;
	(*stack)->prev = NULL;
	if (print == PRINT_R)
		ft_printf("rr\n");
	else if (print == PRINT_A)
		ft_printf("ra\n");
	else if (print == PRINT_B)
		ft_printf("rb\n");
}

void	reverse_rotate(t_list **stack, t_print print)
{
	t_list	*nfirst_node;
	t_list	*nlast_node;
	t_list	*lfisrt_node;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	lfisrt_node = *stack;
	nfirst_node = ft_lstlast(*stack);
	nlast_node = nfirst_node->prev;
	lfisrt_node->prev = nfirst_node;
	nfirst_node->next = lfisrt_node;
	*stack = nfirst_node;
	nlast_node->next = NULL;
	nfirst_node->prev = NULL;
	if (print == PRINT_R)
		ft_printf("rrr\n");
	else if (print == PRINT_A)
		ft_printf("rra\n");
	else if (print == PRINT_B)
		ft_printf("rrb\n");
}

void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
