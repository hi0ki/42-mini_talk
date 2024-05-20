#include "minitalk.h"

void	ft_bzero(char *s)
{
    int     i;

	i = 0;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
}
void    puterror(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    exit(0);
}

void convert_bits(char *str)
{
    char    c;
    int     i;

    c = 0;
    i = 0;
    while (str[i])
    {
        c = c << 1;
        if (str[i] == '1')
        {
            c = c | 1;
        }
        i++;
    }
    write(1, &c, 1);
}