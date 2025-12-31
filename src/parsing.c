/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:41:43 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/31 11:42:13 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static int	digit_argument(char **argv)
{
	long	i;
	long	j;
	long	digit;

	i = 0;
	while (argv[i])
	{
		digit = 0;
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				digit++;
			j++;
		}
		if (digit == 0)
		return (0);
		i++;
	}
	return (1);
}

static int	valid_argument(char *arg)
{
	size_t	digit;
	size_t	i;

	i = 0;
	if (ft_atol(arg) < -2147483648 || ft_atol(arg) > 2147483647)
		return (0);
	while (arg[i])
	{
		digit = 0;
		if (arg[i] == '-' || arg[i] == '+')
			i++;
		while (arg[i])
		{
			if (!ft_isdigit(arg[i]))
				return (0);
			digit++;
			i++;
		}
	}
	if (digit == 0)
		return (0);
	else
		return (1);
}

static void	join_and_split(int argc, char **argv, char ***args)
{
	long	i;
	char	*tmp;
	char	*args_joins;

	i = 0;
	args_joins = ft_calloc((size_t)argc + 1, sizeof(int));
	if (!args_joins)
		return ;
	i = 0;
	while (argv[i])
	{
		tmp = ft_strjoin(argv[i], " ");
		args_joins = ft_strjoin_and_free(args_joins, tmp);
		if (!args_joins)
			return ;
		free(tmp);
		i++;
	}
	*args = ft_split(args_joins, ' ');
	free(args_joins);
}

char	**parsing(int argc, char **argv)
{
	long	i;
	long	loop;
	char	**args;

	i = 0;
	loop = 0;
	if (!digit_argument(argv))
		return (NULL);
	join_and_split(argc, argv, &args);
	while (args[loop])
	{
		i = loop;
		while (args[i])
		{
			if (!valid_argument(args[i])
				|| (args[i + 1] && ft_atol(args[i + 1]) == ft_atol(args[loop])))
			{
				free_split(args);
				return (NULL);
			}
			i++;
		}
		loop++;
	}
	return (args);
}
