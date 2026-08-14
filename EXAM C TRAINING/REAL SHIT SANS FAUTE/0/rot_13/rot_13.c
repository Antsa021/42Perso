#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main (int argc, char **argv)
{
    int i;
    char *str;

    str = argv[1];
    i = 0;
    if (argc == 2)
    {
        while(str[i] != '\0')
        {
            if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
            {
                str[i] = str[i] + 13;
            }
            else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
            {
                str[i] = str[i] - 13;
            }
            ft_putchar(str[i]);
            i++;
        }
    }
    ft_putchar('\n');
    return(0);
}