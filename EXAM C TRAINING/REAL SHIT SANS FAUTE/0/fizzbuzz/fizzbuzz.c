#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
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
        ft_putnbr(nb / 10);
    }
    ft_putchar((nb % 10) + '0');
}

int main(void)
{
    int i;

    i = 1;
    while (i <= 100)
    {
        if (i % 15 == 0)
        {
            write(1, "fizzbuzz", 8);
        }
         else if (i % 3 == 0)
        {
            write(1, "fizz", 4);
        }
        else if (i % 5 == 0)
        {
            write (1, "buzz", 4);
        }
        else
        {
            ft_putnbr(i);
        }
        i++;
        ft_putchar('\n');
    }
    return (0);
}