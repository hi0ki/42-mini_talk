#include "client.h"

void send_bits(char c, int pid)
{
    int div = 128;
    while(div != 0)
    {
        if (c / div)
        {
            kill(pid, SIGUSR1);
            usleep(150);
            c = c % div;
        }
        else
        {
            kill(pid, SIGUSR2);
            usleep(150);
        }
        div = div / 2;
    }
}
void    start(char **av)
{
    int pid;
    int i;

    pid = ft_atoi(av[1]);
    i = 0;
    while(av[2][i])
    {
        send_bits(av[2][i], pid);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        start(av);
    }
}
/*
    10 = 00010100
    7  = 00000111
    res= 00000010
00000001
00000000
<< 1| 1
*/