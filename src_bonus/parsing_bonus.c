/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:41:43 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/20 22:36:07 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static int	is_so_long(char *arg)
{
	int	i;
	int	lenght;

	i = 0;
	while (arg[i] && (arg[i] == '-' || arg[i] == '+'))
		i++;
	while (arg[i] && arg[i] == '0')
		i++;
	lenght = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
		lenght++;
	}
	if (lenght > 11)
		return (0);
	return (1);
}

static int	valid_argument(char *arg)
{
	size_t	digit;
	size_t	i;

	i = 0;
	if (!is_so_long(arg))
		return (0);
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
	return (1);
}

static int	join_and_split(int argc, char **argv, char ***args)
{
	long	i;
	char	*args_joins;

	i = 0;
	args_joins = ft_calloc((size_t)argc + 1, sizeof(char));
	if (!args_joins)
		return (0);
	i = 0;
	while (argv[i])
	{
		args_joins = ft_strjoin_space_and_free(args_joins, argv[i]);
		if (!args_joins)
			return (0);
		i++;
	}
	*args = ft_split(args_joins, ' ');
	free(args_joins);
	return (1);
}

char	**parsing_bonus(int argc, char **argv)
{
	long	i;
	long	loop;
	char	**args;

	i = 0;
	loop = -1;
	if (!digit_argument(argv))
		return (NULL);
	if (!join_and_split(argc, argv, &args))
		return (NULL);
	while (args[++loop])
	{
		i = loop;
		while (args[i])
		{
			if (!valid_argument(args[i])
				|| (args[i + 1] && ft_atol(args[i + 1]) == ft_atol(args[loop])))
			{
				free_split_bonus(args);
				return (NULL);
			}
			i++;
		}
	}
	return (args);
}
