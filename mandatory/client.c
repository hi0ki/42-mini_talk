/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:47:00 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/21 12:47:04 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(unsigned char c, int pid)
{
	int	div;

	div = 128;
	while (div > 0)
	{
		if (c >= div)
		{
			kill(pid, SIGUSR1);
			c -= div;
		}
		else
			kill(pid, SIGUSR2);
		div = div / 2;
		usleep(150);
	}
}

void	start(char **av)
{
	int	pid;
	int	i;

	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		send_bits(av[2][i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	start(av);
}
