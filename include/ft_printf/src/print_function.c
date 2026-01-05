/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:49:01 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/03 10:34:17 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		len += write(1, &s[i], 1);
		i++;
	}
	return (len);
}

int	ft_putchar(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_putnb_base(long long n, char *base)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		i += ft_putnb_base(n / 10, base);
	i += ft_putchar(base[n % 10]);
	return (i);
}

int	ft_putnb_base_hexa(unsigned long n, char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_putnb_base_hexa(n / 16, base);
	i += ft_putchar(base[n % 16]);
	return (i);
}

int	ft_printptr(void *ptr)
{
	int	len;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = write(1, "0x", 2);
	len += ft_putnb_base_hexa((unsigned long)ptr, HEXA_LOWER_BASE);
	return (len);
}
