#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
    if (nb == -2147483648 )
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');
}

void	pgcd(int a, int b)
{
	int n = a;

	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		{
			ft_putnbr(n);
			return;
		}
		n--;
	}
}

int     ft_atoi(const char *str)
{
	int	nbr;
	int sig;
	int	i;

	nbr = 0;
	sig = 1;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sig = -1;
		i = i + 1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sig);
}


int		main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(ft_atoi(argv[1]), atoi(argv[2]));

	ft_putchar('\n');
	return (0);
}