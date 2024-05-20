#include "minitalk.h"

void    send_len(int len, int pid)
{
    char    *str;
    int     i;

    i = 3;
    printf("%d\n", len);
    str = (char *)&len;
    while (i >= 0)
    {
        send_bits(str[i], pid);
        i--;
    }
}
void send_bits(unsigned char c, int pid)
{
    int div = 128;
    while(div > 0)
    {
        if (c >= div)
        {
            kill(pid, SIGUSR1);
            printf("1");
            c -= div;
        }
        else
        {
            printf("0");
            kill(pid, SIGUSR2);
        }
        div = div / 2;
        usleep(150);
    }
    printf(" ");
}
void    start(char **av)
{
    int pid;
    int i;

    pid = ft_atoi(av[1]);
    i = 0;
    send_len(ft_strlen(av[2]), pid);
    while (av[2][i])
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
