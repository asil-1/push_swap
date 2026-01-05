/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:10:24 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/03 10:33:28 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	check_character(char c, va_list list)
{
	int		len;

	if (c == '%')
		len = write(1, "%", 1);
	if (c == 's')
		len = ft_putstr(va_arg(list, char *));
	if (c == 'c')
		len = ft_putchar(va_arg(list, int));
	if (c == 'i' || c == 'd')
		len = ft_putnb_base(va_arg(list, int), HEXA_LOWER_BASE);
	if (c == 'p')
		len = ft_printptr(va_arg(list, void *));
	if (c == 'u')
		len = ft_putnb_base(va_arg(list, unsigned int), HEXA_LOWER_BASE);
	if (c == 'x')
		len = ft_putnb_base_hexa(va_arg(list, unsigned int), HEXA_LOWER_BASE);
	if (c == 'X')
		len = ft_putnb_base_hexa(va_arg(list, unsigned int), HEXA_UPPER_BASE);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		len;
	int		i;

	if (!s)
		return (-1);
	len = 0;
	va_start (list, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			len += check_character(*(s + i + 1), list);
			i += 2;
			continue ;
		}
		len += write(1, &s[i], 1);
		i++;
	}
	va_end (list);
	return (len);
}
