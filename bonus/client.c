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

void	handler(int num)
{
	if (num == SIGUSR1)
	{
		ft_printf("Successfully\n");
		exit(EXIT_SUCCESS);
	}
}

void	send_len(size_t	len, int pid)
{
	char	*str;
	int		i;

	i = 7;
	str = (char *)&len;
	while (i >= 0)
	{
		send_bits(str[i], pid);
		i--;
	}
}

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
		{
			kill(pid, SIGUSR2);
		}
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
	send_len(ft_strlen(av[2]), pid);
	while (av[2][i])
	{
		send_bits(av[2][i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, &handler);
	if (ac == 3)
	{
		start(av);
		while (1)
			pause();
	}
	return (0);
}
