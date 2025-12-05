/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:44:29 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/05 16:41:30 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//anciennement ft_lstnew
t_list	*ft_newnode(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
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
		new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*tmp;
	t_list	*newlst;
	t_list	*newnode;

	newlst = 0;
	while (lst && f && del)
	{
		tmp = f(lst->content);
		newnode = ft_newnode(tmp);
		if (!newnode)
		{
			del(tmp);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*node4;
// 	t_list	*node5;
// 	char	*a = "bonjour";
// 	char	*b = "le";
// 	char	*c = "jour";
// 	char	*d = "je";
// 	char	*e = "suis";

// 	node1 = ft_newnode(a);
// 	node2 = ft_newnode(b);
// 	node3 = ft_newnode(c);
// 	node4 = ft_newnode(d);
// 	node5 = ft_newnode(e);
// 	ft_lstadd_front(&node5, node4);
// 	ft_lstadd_front(&node4, node3);
// 	ft_lstadd_front(&node3, node2);
// 	ft_lstadd_front(&node2, node1);
// 	printf("%d\n", ft_lstsize(node1));
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	free(node4);
// 	free(node5);
// }