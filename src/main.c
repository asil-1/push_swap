/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:34:02 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/20 22:09:51 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_stack(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			tmp_a = stack_a;
			stack_a = stack_a->next;
			free(tmp_a);
		}
		if (stack_b)
		{
			tmp_b = stack_b;
			stack_b = stack_b->next;
			free(tmp_b);
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	size_t	nb_node;

	if (argc <= 1)
		return (0);
	nb_node = 0;
	stack_a = NULL;
	stack_b = NULL;
	nb_node = init_stack(argc, argv, &stack_a);
	sort(&stack_a, &stack_b, nb_node);
	free_stack(stack_a, stack_b);
	return (0);
}
