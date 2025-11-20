#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	*arr;
	int	i = 0;

	if (start < end)
		len = end - start;
	else
		len = start - end;
	arr = (int *)malloc(sizeof(int) * (len + 1));
	while (start != end)
	{
		arr[i] = start;
		i++;
		if (start < end)
			start++;
		else
			start--;
	}
	arr[i] = end;
	return (arr);
}
