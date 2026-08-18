#include <unistd.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int	c;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			c = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = c;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}