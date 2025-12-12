/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:44:29 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/08 17:49:08 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//anciennement ft_lstnew
t_list	*ft_newnode(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_list));
	new->content = content;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
		(*lst)->prev = new;
		new->next = *lst;
		new->prev = NULL;
	}
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		new->prev = ft_lstlast(*lst);
		ft_lstlast(*lst)->next = new;
		new->next = NULL;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*node4;

// 	t_list	*tmp;
// 	t_list	*tmp2;
// 	char	*a = "le raccoon";
// 	char	*b = "mange";
// 	char	*c = "une";
// 	char	*d = "pizza";

// 	node1 = ft_newnode(a);
// 	node2 = ft_newnode(b);
// 	node3 = ft_newnode(c);
// 	node4 = ft_newnode(d);
// 	// ft_lstadd_front(&node4, node3);
// 	// ft_lstadd_front(&node1, node3);
// 	// ft_lstadd_front(&node3, node4);

// 	ft_lstadd_back(&node1, node2);
// 	ft_lstadd_back(&node2, node3);
// 	ft_lstadd_back(&node3, node4);

// 	tmp = node1;
// 	while (tmp)
// 	{
// 		printf("%s ", (char *)tmp->content);
// 		tmp2 = tmp;
// 		tmp = tmp->next;
// 		free(tmp2);
// 	}
// }