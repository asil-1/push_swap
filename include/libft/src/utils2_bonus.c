/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:22:41 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/27 14:01:00 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
#include <stdio.h>
int	ft_lstnsize(t_list *lst, int nb)
{
	int	count;

	count = 0;
	while (lst && lst->content != nb)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstfirst(t_list *lst)
{
	while (lst && lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}