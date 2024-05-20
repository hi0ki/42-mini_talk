#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

typedef struct server{
	int	bits;
	int	pid;
	int len;
	int i;
	char str[8];
	char s1[32];
}t_server;
int	ft_atoi(char *str);
void send_bits(unsigned char c, int pid);
void	ft_bzero(char *s);
void convert_bits(char *str);
void    puterror(char *str);
int ft_strlen(char *str);

#endif