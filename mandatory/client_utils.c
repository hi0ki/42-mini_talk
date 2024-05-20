#include "minitalk.h"

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

int check_atoi(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        i++;
    }
    return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	long 	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
    if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (check_atoi(str + i) == -1)
        puterror("PID NOT CORRECT\n");
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
