#include <stdlib.h>

int	*ft_range(int start, int end)
{
    int	len;
    int	i;
    int	*arr;

    if (start < end)
        len = end - start;
    else
        len = start - end;
    arr = (int *)malloc(sizeof(int) * (len + 1));
    if (!arr)
        return (NULL);
    i = 0;
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
