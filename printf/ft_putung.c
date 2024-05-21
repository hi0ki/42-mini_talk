/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putung.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:28:38 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/01/05 21:44:56 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	c_nbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_putung(unsigned int n)
{
	int	i;

	i = c_nbr(n);
	if (n > 9)
	{
		ft_putung(n / 10);
		ft_putung(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (i);
}
