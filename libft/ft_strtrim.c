/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:36:31 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/03 18:24:48 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end]))
		end--;
	result = ft_substr(s1, start, end - start + 1);
	return (result);
}

// int	main(void)
// {
// 	char	s1[] = "kayakraccoonkayak";
// 	char	set[] = "yka";
// 	char	*trim;

// 	trim = ft_strtrim(s1, set);
// 	printf("%s\n", trim);
// 	free(trim);
// }
