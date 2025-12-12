/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:16:41 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/12 11:27:10 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack_a(t_list	**stack_a, int content)
{
	t_list	*node;

	node = ft_newnode(content);
	ft_lstadd_back(stack_a, node);
}

void	swap(t_list **stack)
{
	t_list	*node;

	if (!(*stack)->next)
		return ;
	node = (*stack)->next;
	(*stack)->prev = node;
	(*stack)->next = node->next;
	node->next = *stack;
	node->prev = NULL;
	*stack = node;
}

void	rotate(t_list **stack)
{
	t_list	*nfirst_node;
	t_list	*nlast_node;
	t_list	*last_node;

	if (!(*stack)->next)
		return ;
	nfirst_node = (*stack)->next;
	nlast_node = (*stack);
	last_node = ft_lstlast(*stack);
	last_node->next = nlast_node;
	nlast_node->prev = last_node;
	nlast_node->next = NULL;
	*stack = nfirst_node;
	(*stack)->prev = NULL;
}

void reverse_rotate(t_list **stack)
{
	t_list	*nfirst_node;
	t_list	*nlast_node;
	t_list	*lfisrt_node;

	if (!(*stack)->next)
		return ;
	lfisrt_node = (*stack);
	nfirst_node = ft_lstlast(*stack);
	nlast_node = nfirst_node->prev;
	lfisrt_node->prev = nfirst_node;
	nfirst_node->next = lfisrt_node;
	*stack = nfirst_node;
	nlast_node->next = NULL;
	nfirst_node->prev = NULL;
}

//faire fonction push
//faire apparaitre stack b a cote de stack a
//mettre des choses dans stack b
//push a
//push b

int	main(int argc, char **argv)
{
	t_list	*stack_a;
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
	while (i < argc)
	{
		init_stack_a(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	reverse_rotate(&stack_a);
	write (1, "stack_a :\n", 10);
	t_list	*tmp;
	t_list	*tmp2;
	tmp = stack_a;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	return (0);
}
