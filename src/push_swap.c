/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:16:41 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/19 13:13:40 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	presorting(t_list **stack_a, t_list **stack_b)
// {
// 	int	n;
// 	int	delta;
// 	int	threshold;

// 	n = ft_lstsize(*stack_a);
// 	delta = n / 20 + 7;
// 	threshold = 0;
// 	while (*stack_a)
// 	{
// 		if ((*stack_a)->content <= delta + threshold)
// 		{
// 			push()
// 		}
// 	}
// }

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char **args;
	int	i;

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
	if (i <= 3)
		sort_3_nb(&stack_a); /*on peut ne faire apparaitre stack b que dans les fonctions*/
	free(args);
	// swap(&stack_a);
	write (1, "sa: sb:\n", 9);
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*tmp_a2;
	t_list	*tmp_b2;
	tmp_a = stack_a;
	tmp_b = stack_b;
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			printf("%d   ", tmp_a->content);
			tmp_a2 = tmp_a;
			tmp_a = tmp_a->next;
			free(tmp_a2);
		}
		if (tmp_b)
		{
			printf("%d", tmp_b->content);
			tmp_b2 = tmp_b;
			tmp_b = tmp_b->next;
			free(tmp_b2);
		}
		printf("\n");
	}
	return (0);
}
