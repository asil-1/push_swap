/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:01:45 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/19 13:32:46 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3_nb(t_list **stack_a)
{
	while (1)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			swap(&(*stack_a));
			printf("swapin (*stack_a).content %d\n", (*stack_a)->content);
		}
		if ((*stack_a)->content > ft_lstlast((*stack_a))->content)
		{
			reverse_rotate(&(*stack_a));
			printf("rrotate (*stack_a).content %d\n", (*stack_a)->content);
		}
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			swap(&(*stack_a));
			printf("swap2 (*stack_a).content %d\n", (*stack_a)->content);
		}
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
		{
			reverse_rotate(&(*stack_a));
			printf("rrotate2 (*stack_a).content %d\n", (*stack_a)->content);
			continue ;
		}
		else
			break ;
	}
}

/*si besoin d'ameliorer traiter cas par cas*/