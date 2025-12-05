/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:18:09 by ldepenne          #+#    #+#             */
/*   Updated: 2025/10/25 14:29:29 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(sizeof(char) * size);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, size);
	ft_strlcat(join, s2, size);
	return (join);
}

// int	main(void)
// {
// 	char	*s1 = NULL;
// 	char	s2[] = " un test";
// 	char	*result;

// 	// result = ft_strlcat(s1, s2, ft_strlen(s1)+ft_strlen(s2) + 1);
// 	result = ft_strjoin(s1, s2);
// 	printf("%s\n", result);
// 	free(result);
// }
