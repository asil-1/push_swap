/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:51:23 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/31 11:29:11 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !del)
		return ;
	tmp = (*lst);
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		ft_lstdelone(tmp2, del);
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	int		tmp;
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
