/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:09:18 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/01/09 18:35:55 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_help(char c, va_list count)
{
	int	nb;

	nb = 0;
	if (c == 's')
		nb += ft_putstr(va_arg(count, char *));
	else if (c == 'c')
		nb += ft_putchar(va_arg(count, int));
	else if (c == 'd' || c == 'i')
		nb += ft_putnbr(va_arg(count, int));
	else if (c == 'u')
		nb += ft_putung(va_arg(count, unsigned int));
	else if (c == 'x' || c == 'X')
		nb += ft_putx(va_arg(count, unsigned int), c);
	else if (c == 'p')
	{
		nb += ft_putstr("0x");
		nb += ft_putp(va_arg(count, unsigned long));
	}
	else if (c == '%')
		nb += ft_putchar('%');
	return (nb);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		nb;
	va_list	count;

	i = 0;
	nb = 0;
	va_start(count, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			nb += ft_help(format[i], count);
		}
		else if (format[i] != '%')
			nb += ft_putchar(format[i]);
		i++;
	}
	va_end(count);
	return (nb);
}
