/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:16:41 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/30 13:51:40 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_list *stack_a, t_list * stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	write (1, "\nsa:\tsb:\n", 9);
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%d", stack_a->content);
			tmp_a = stack_a;
			stack_a = stack_a->next;
			free(tmp_a);
		}
		if (stack_b)
		{
			printf("\t%d", stack_b->content);
			tmp_b = stack_b;
			stack_b = stack_b->next;
			free(tmp_b);
		}
		printf("\n");
	}
}

int	init_stack(int argc, char **argv, t_list **stack_a)
{
	size_t	nb;
	char	**args;

	nb = 0;
	args = parsing(argc - 1, argv + 1);
	if (!args)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	while (args[nb])
	{
		init_stack_a(stack_a, ft_atoi(args[nb]));
		free(args[nb]);
		nb++;
	}
	free(args);
	return (nb);
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
	what_sort(&stack_a, &stack_b, nb_node);
	free_stack(stack_a, stack_b);
	return (0);
}
