/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:40:38 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/21 15:18:12 by ldepenne         ###   ########.fr       */
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

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack_bonus(argc, argv, &stack_a))
		return (0);
	if (!cmd_bonus(&stack_a, &stack_b))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	ft_printf("%d\n", is_sort_bonus(&stack_a));
	if (ft_lstsize(stack_a) == argc - 1 && ft_lstsize(stack_b) == 0
		&& is_sort_bonus(&stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(stack_a, stack_b);
	return (0);
}
