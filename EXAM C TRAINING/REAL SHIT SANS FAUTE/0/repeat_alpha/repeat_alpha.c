#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    char *str;

    str = argv[1];
    i = 0;
    if (argc == 2)
    {
        while (str[i] != '\0')
        {
            j = 1;
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                j = str[i] - 96;
            }
            else if (str[i] >= 'A' && str[i] <= 'Z')
            {
                j = str[i] - 64;
            }
            while (j > 0)
            {
                ft_putchar(str[i]);
                j--;
            }
            i++;
        }
    }
    ft_putchar('\n');
    return(0);
}