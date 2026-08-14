#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

int main (int argc, char ** argv)
{
    int i;
    char *str;

    i = 0;
    str = argv[1];
    if(argc == 2)
    {
        while (str[i] != '\0')
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
            else if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + 32;
            }
            ft_putchar(str[i]);
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}