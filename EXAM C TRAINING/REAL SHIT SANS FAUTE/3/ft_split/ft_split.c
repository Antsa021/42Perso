#include <unistd.h>
#include <stdlib.h>

char **ft_split(char *str)
{
	char **resultat = malloc(sizeof(char *) * 1000);
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;

	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		{
			i++;
		}
		if (str[i] != '\0')
		{
			k = i;
			while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			{
				i++;
			}
			resultat[j] = malloc(i - k + 1);
			int	l =0;
			while (k < i)
			{
				resultat[j][l++] = str[k++];
			}
			resultat[j][l] = '\0';
			j++;
		}
	}
	resultat[j] = 0;
	return (resultat);
}
