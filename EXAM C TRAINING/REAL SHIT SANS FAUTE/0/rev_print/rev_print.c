#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

int main (int argc, char **argv)
{
    int i;
    char *str;

    str = argv[1];
    i = 0;
    if (argc == 2)
    {
        while (str[i] != '\0')
        {
            i++;
        }
        i--;
        while (i >= 0)
        {
            ft_putchar(str[i]);
            i--;
        }
    }
    ft_putchar('\n');
    return(0);
}