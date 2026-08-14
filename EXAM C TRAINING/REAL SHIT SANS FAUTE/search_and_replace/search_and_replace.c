#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return(i);
}

int		main(int argc, char **argv)
{
    int i;
    char *str;

    str = argv[1];
    i = 0;
	if (argc == 4)
    {
		if (ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
        {
			while(str[i] != '\0')
            {
				if (str[i] == argv[2][0])
                {
                    str[i] = argv[3][0];
                }
                ft_putchar(str[i]);
				i++;
			}
		}
	}
	ft_putchar('\n');
    return (0);
}