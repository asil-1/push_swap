/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:01:45 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/19 10:40:56 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3_nb(t_list **stack_a)
{
	t_list	*node;

	node = *stack_a;

	if (node->content > node->next->content)
		swap(&(*stack_a));
	if (node->content > ft_lstlast(node)->content)
		reverse_rotate(&(*stack_a));
	// if (node->content > node->next->content)
		// swap(&(*stack_a));
}

/*si besoin d'ameliorer traiter cas par cas*/