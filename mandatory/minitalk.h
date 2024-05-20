#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(char *str);
void send_bits(unsigned char c, int pid);
void	ft_bzero(char *s);
void convert_bits(char *str);
void    puterror(char *str);

#endif