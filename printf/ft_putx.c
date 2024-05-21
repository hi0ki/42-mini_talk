/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:55:15 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/01/09 17:21:45 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putx(unsigned int nb, char c)
{
	char	*str;
	int		cnt;

	cnt = 0;
	if (c == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (nb >= 16)
	{
		cnt += ft_putx((nb / 16), c);
	}
	cnt += ft_putchar(str[nb % 16]);
	return (cnt);
}
