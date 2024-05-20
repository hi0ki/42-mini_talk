#include "minitalk.h"

void send_bits(unsigned char c, int pid)
{
    int div = 128;
    while(div > 0)
    {
        if (c >= div)
        {
            kill(pid, SIGUSR1);
            // printf("1");
            c -= div;
        }
        else
        {
            // printf("0");
            kill(pid, SIGUSR2);
        }
        div = div / 2;
        usleep(200);
    }
}
void    start(char **av)
{
    int pid;
    int i;

    pid = ft_atoi(av[1]);
    i = 0;
    while(av[2][i])// 11110000 10011111 10011000 10000000
    {
        // printf("i = %d\n", i);
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
