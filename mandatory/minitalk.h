/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:47:08 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/21 12:47:10 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct server{
	int		pid;
	int		i;
	char	str[8];
}t_server;

int		ft_atoi(char *str);
void	send_bits(unsigned char c, int pid);
void	ft_bzero(char *s);
void	convert_bits(char *str);
void	puterror(char *str);

#endif
