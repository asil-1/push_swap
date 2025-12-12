/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:28:50 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/11 17:11:30 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"
# include <unistd.h>
# include <stdio.h> // a enlever

int		parsing(char **arg);
void	init_stack_a(t_list	**stack_a, int content);
void	swap(t_list **stack);

#endif