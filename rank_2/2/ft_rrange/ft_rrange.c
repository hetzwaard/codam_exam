#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int len;
	int *arr;
	int i = 0;

	if (start > end)
		len = start - end;
	else
		len = end - start;
	arr = malloc(sizeof(int) * (len + 1));
	while (i <= len)
	{
		arr[i] = end;
		i++;
		if (start > end)
			end++;
		else
			end--;
	}
	return (arr);
}
