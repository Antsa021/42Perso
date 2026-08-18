#include <stdlib.h>

int	absolute_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	*ft_range(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	size = absolute_value((end - start)) + 1;
	res = malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	if (start < end)
	{
		while (start <= end)
		{
			res[i] = start;
			start = start + 1;
			i = i + 1;
		}
	}
	else
	{
		while (start >= end)
		{
			res[i] = start;
			start = start - 1;
			i = i + 1;
		}
	}
	return (res);
}