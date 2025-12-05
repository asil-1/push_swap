/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:46:59 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/14 14:16:18 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	check;
	char	*result;

	if (s == NULL)
		return (NULL);
	check = ft_strlen(s);
	if (check - start > 0 && check - start < len)
		len = check - start;
	if (start >= check)
		len = 0;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		result[j] = s[start];
		start++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char	s[] = "";
// 	unsigned int	strat = 0;
// 	size_t len = 1;
// 	char	*result;

// 	result = ft_substr(s, strat, len);
// 	printf("%s\n", result);
// 	free(result);
// }
