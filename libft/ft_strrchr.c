/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:44:46 by ldepenne          #+#    #+#             */
/*   Updated: 2025/10/30 11:44:58 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*stock;

	stock = s;
	while (*s)
		s++;
	while (s != stock && !(*s == (char)c))
		s--;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
