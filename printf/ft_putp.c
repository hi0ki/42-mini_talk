/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:29:24 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/01/05 21:44:34 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(unsigned long nb)
{
	char	*str;
	int		cnt;

	str = "0123456789abcdef";
	cnt = 0;
	if (nb >= 16)
		cnt += ft_putp(nb / 16);
	cnt += ft_putchar(str[nb % 16]);
	return (cnt);
}
