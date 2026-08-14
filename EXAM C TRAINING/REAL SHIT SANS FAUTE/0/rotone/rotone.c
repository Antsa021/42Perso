#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i;
    char *str;

    str = argv[1];
    i = 0;
    if (argc == 2)
   {
    while (str[i] != '\0')
    {
        if ((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y'))
        {
            str[i] = str[i] + 1;
        }
        else if (str[i] == 'z' || str[i] == 'Z')
        {
            str[i] = str[i] - 25;
        }
        ft_putchar(str[i]);
        i++;
    }
   }
   ft_putchar('\n');
   return(0);
}