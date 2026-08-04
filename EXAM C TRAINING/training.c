//first word

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        write (1, "-2147483648", 11);
    }
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
    {
        ft_putnbr(nb/10);
    }
    ft_putchar((nb % 10) + '0');
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
        {
            i++;
        }
        while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
        {
            ft_putchar(argv[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}

int main(void)
{
    int i;

    i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            write(1, "fizzbuzz", 8);
        }
        else if (i % 3 == 0)
        {
            write(1, "fizz", 4);
        }
        else if (i % 5 == 0)
        {
            write(1, "buzz", 4);
        }
        else
        {
            ft_putnbr(i);
        }
        ft_putchar('\n');
        i++;
    }
    return (0);
}

void	ft_putstr(char *str)
{
    int i;

    i  = 0;
    while (str != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

char    *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++
    }
    s1[i] = '\0';
    return (s1);
}

int	ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

void	ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main (int argc, char **argv)
{
    int i;
    int k;
    char    *str;

    i = 0;
    k = 1;

    if (argc ==  2)
    {
        str = argv[1];
        while (str[i] != '\0')
        {
            k = 1;
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                k = str[i] - 96;
            }
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                k = str[i] - 64;
            }
            while (k >= 1)
            {
                ft_putchar(str[i]);
                k--;
            }
            i++;
        }
    
    }
    ft_putchar('\n');
    return(0);
}

int main (int argc, char **argv)

{
	int	i = 0;

	if (argc == 2)
	{
		while (argv[1][i] != '\0')
			i++;
		while (i != 0)
        {
            --i;
			write(1, &argv[1][i], 1);
        }
	}
	write(1, "\n", 1);
	return (0);
}

int main (int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if ((argv[1][i] >= 'a' && argv[1][i] <= 'm') || (argv[1][i] >= 'A' && argv[1][i] <= 'M'))
            {
                argv[1][i] = argv[1][i] + '13';
            }
            if ((argv[1][i] >= 'n' && argv[1][i] <= 'z') || (argv[1][i] >= 'N' && argv[1][i] <= 'Z'))
            {
                argv[1][i] = argv[1][i] + '13';
            }
            ft_putchar(i);
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}

int main(int argc,  char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if((argv[1][i] >= 'a' && argv[1][i] <= 'y') || (argv[1][i] >= 'A' && argv[1][i] >= 'Y'))
            {
                argv[1][i] = argv[1][i] + 1;
            }
            if(argv[1][i] == 'z' && argv[1][i] == 'Z')
            {
                argv[1][i] = argv[1][i] - 25;
            }
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}

int main (int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 4)
    {
        while ((argv[2][0] >= 'a' && argv[2][0] <= 'z') ||(argv[2][0] >= 'A' && argv[2][0] <= 'Z') && (argv[2][1] != '\0'))
        {
            while ((argv[3][0] >= 'a' && argv[2][0] <= 'z') ||(argv[3][0] >= 'A' && argv[3][0] <= 'Z') && (argv[3][1] != '\0'))
            {
                while (argv[1][i] != '\0')
                {
                    if (argv[1][i] == argv[2][0])
                    {
                        argv[1][i] = argv[3][0];
                    }
                    ft_putchar(argv[1][i]);
                    i++;
                }
            }
        }
    }
    ft_putchar('\n');
    return (0);
}

int main (int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                argv[1][i] = argv[1][i] + 32;
            }
            if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                argv[1][i] = argv[1][i] - 32;
            }
            ft_putchar(argv[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}














