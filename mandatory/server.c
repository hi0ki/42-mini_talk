#include "minitalk.h"

void    handler(int num, siginfo_t *sig, void *data)
{
    static int  i;
    static char str[9];
    static int  pid;

    if (pid != sig->si_pid)
    {
        pid = sig->si_pid;
        ft_bzero(str);
        i = 0;
    }
    if (num == SIGUSR1)
        str[i] = '1';
    else if (num == SIGUSR2)
        str[i] = '0';
    i++;
    if (i == 8)
    {
        str[i] = '\0';
        i = 0;
        convert_bits(str);
    }
}
int main(int ac, char **av)
{
    struct sigaction sa;
    if (ac == 1)
    {
        printf("pid %d\n", getpid());
        sa.sa_sigaction = handler;
        sa.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        while (1);
    }
    else
        puterror("only one arg bebe\n");  
}
