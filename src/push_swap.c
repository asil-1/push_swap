/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:16:41 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/29 19:22:17 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print(t_list *stack_a, t_list * stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	// write (1, "\nsa:\tsb:\n", 9);
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			// printf("%d", stack_a->content);
			tmp_a = stack_a;
			stack_a = stack_a->next;
			free(tmp_a);
		}
		if (stack_b)
		{
			// printf("\t%d", stack_b->content);
			tmp_b = stack_b;
			stack_b = stack_b->next;
			free(tmp_b);
		}
		// printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	size_t	i;

	if (argc <= 1)
		return (0);
	args = parsing(argc - 1, argv + 1);
	if (!args)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (args[i])
	{
		init_stack_a(&stack_a, ft_atoi(args[i]));
		free(args[i]);
		i++;
	}
	free(args);
	what_sort(&stack_a, &stack_b, i);
	print(stack_a, stack_b);
	return (0);
}
