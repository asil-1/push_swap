/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:45:59 by ldepenne          #+#    #+#             */
/*   Updated: 2025/10/29 21:26:44 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//pas push cette fonction
// char	mapi(unsigned int i, char c)
// {
// 	c = c + i;
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;
	unsigned int	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	mapi = malloc(sizeof(*mapi) * (size + 1));
	if (!mapi)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}

// int	main(void)
// {
// 	char const	s[] = "raccoon rocket";
// 	char	*print;

// 	print = ft_strmapi(s, NULL);
// 	printf("%s\n", print);
// 	free(print);
// }

// void *F;

// F = NULL;

// ft_strmapi("hello", F);
