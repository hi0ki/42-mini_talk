/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:47:18 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/21 12:47:21 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_char(int num, t_server *s)
{
	if (num == SIGUSR1)
		s->str[s->i] = '1';
	else if (num == SIGUSR2)
		s->str[s->i] = '0';
	s->i++;
}

void	handler(int num, siginfo_t *sig, void *data)
{
	static t_server	s;

	(void)data;
	if (s.pid != sig->si_pid)
	{
		s.pid = sig->si_pid;
		ft_bzero(s.str);
		s.i = 0;
	}
	get_char(num, &s);
	if (s.i == 8)
	{
		s.str[s.i] = '\0';
		s.i = 0;
		convert_bits(s.str);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac == 1)
	{
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
		ft_printf("PID: %d\n", getpid());
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	else
		puterror("only one arg bebe\n");
}
