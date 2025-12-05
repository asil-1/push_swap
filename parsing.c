/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:33:15 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/05 16:31:29 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(char **arg)
{
	long	i;
	long	j;
	long	loop;

	loop = 0;
	while (arg[loop])
	{
		i = loop;
		while (arg[i])
		{
			j = 0;
			if (ft_atol(arg[i]) < -2147483648 || ft_atol(arg[i]) > 2147483647)
				return (0);
			while(arg[i][j])
			{
				if (!ft_isdigit(arg[i][j]) && arg[i][j] != '-')
					return (0);
				j++;
			}
			i++;
			if (ft_atol(arg[i]) == ft_atol(arg[loop]) && arg[i])
				return (0);
		}
		loop++;
	}
	return (1);
}
