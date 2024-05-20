#include "minitalk.h"


/*

    * khas nkml get_len li atb9a takhd 32 f string o ngad liha function kat
    dat lbits l int bha convert bits
    osafi dik sa3 ndir malloc 

    >>>>> b9aa liya ha ndir convert bits "int"

*/
void get_char(int num, t_server *s)
{
    if (num == SIGUSR1)
        s->str[s->i] = '1';
    else if (num == SIGUSR2)
        s->str[s->i] = '0';
    s->i++;
}
void get_len(int num, t_server *s)
{
    if (num == SIGUSR1)
        s->s1[s->bits] = '1';
    else if (num == SIGUSR2)
        s->s1[s->bits] = '0';
    s->bits++;
    if (s->bits == 32)
    {
        s->s1[s->bits] = '\0';
        printf("%s\n", s->s1);
    }
}
void    handler(int num, siginfo_t *sig, void *data)
{
    static t_server s;

    if (s.pid != sig->si_pid)
    {
        s.pid = sig->si_pid;
        ft_bzero(s.str);
        // ft_bzero(s.s1);
        s.i = 0;
    }
    if (s.bits < 32)
        get_len(num, &s);
    else
        get_char(num, &s);
    if (s.i == 8)
    {
        s.str[s.i] = '\0';
        s.i = 0;
        convert_bits(s.str);
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
