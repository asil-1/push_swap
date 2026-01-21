/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:21:34 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/20 15:18:19 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin_space_and_free(char *s1, char *s2)
{
	char	*result;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = ' ';
	result[i + 1] = '\0';
	ft_memcpy(result + i + 1, s2, ft_strlen(s2) + 1);
	free(s1);
	return (result);
}
