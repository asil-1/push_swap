/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:33:15 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/11 14:40:19 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	valid_argument(char *arg)
{
	size_t	isdigit;
	size_t	i;

	i = 0;
	if (ft_atol(arg) < -2147483648 || ft_atol(arg) > 2147483647)
			return (1);
		while(arg[i])
		{
			isdigit = 0;
			while (arg[i] && (arg[i] == '-' || arg[i] == '+'))
				i++;
			while (arg[i] && (arg[i] >= '0' && arg[i] <= '9'))
			{
				isdigit++;
				i++;
			}
		}
	if (isdigit > 0)
		return (0);
	else
		return (1);
}

int	parsing(char **argv)
{
	long	i;
	long	loop;
	// char	*argsjoin;
	// char	*tmp;

	i = 0;
	// while (argv[i])
	// {
	// 	tmp = ft_strjoin(argsjoin, argv[i]);
	// 	argsjoin = tmp;
	// 	i++;
	// }
	loop = 0;
	while (argv[loop])
	{
		i = loop;
		while (argv[i])
		{
			if (valid_argument(argv[i]))
				return (1);
			i++;
			if (ft_atol(argv[i]) == ft_atol(argv[loop]) && argv[i])
				return (1);
		}
		loop++;
	}
	return (0);
}


