/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:16:41 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/05 16:30:05 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a(char **arg)
{

}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		ft_putendl_fd("caca", 2);
		return (0);
	}
	--argc;
	++argv;
	if (!parsing(argv))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	write (1, "ok", 2);
	// stack_a(argv);
	return (0);
}