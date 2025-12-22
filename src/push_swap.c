/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:16:41 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/22 14:00:29 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print(t_list *stack_a, t_list * stack_b)
{
	write (1, "sa:\tsb:\n", 9);

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
			printf("%d", tmp_a->content);
			tmp_a2 = tmp_a;
			tmp_a = tmp_a->next;
			free(tmp_a2);
		}
		if (tmp_b)
		{
			printf("\t%d", tmp_b->content);
			tmp_b2 = tmp_b;
			tmp_b = tmp_b->next;
			free(tmp_b2);
		}
		printf("\n");
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
	stack_b = NULL; /*la faire apparaitre dans la fonction de tri direct, la faire apparaitre ici ne sert que a l'afiichage*/
	while (args[i])
	{
		init_stack_a(&stack_a, ft_atoi(args[i]));
		free(args[i]);
		i++;
	} /*mettre cette boucle dans une autre fonction*/
	free(args);
	what_sort(&stack_a, &stack_b, i);
	print(stack_a, stack_b);
	return (0);
}
