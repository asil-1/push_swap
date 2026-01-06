/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:44:29 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/05 19:42:09 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
		(*lst)->prev = new;
		new->next = *lst;
	}
	new->prev = NULL;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
	}
	else
	{
		new->prev = ft_lstlast(*lst);
		ft_lstlast(*lst)->next = new;
	}
	new->next = NULL;
}
