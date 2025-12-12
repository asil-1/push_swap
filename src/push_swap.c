/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:16:41 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/12 14:50:25 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//faire fonction push
//faire apparaitre stack b a cote de stack a
//mettre des choses dans stack b
//push a
//push b

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	i;

	if (argc <= 1)
		return (0);
	--argc;
	++argv;
	if (parsing(argv))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		init_stack_a(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	reverse_rotate(&stack_b);
	write (1, "stack_a :   stack_b ;\n", 22);
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
