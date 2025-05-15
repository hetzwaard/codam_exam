#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	size_t j = 0;
	
	while (s[i] != '\0')
	{
		j = 0;
		while(reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

// #include <stdio.h>

// int main(void)
// {
// 	const char *x = "MerhabaDun";
// 	const char *y = "abaDu";
// 	printf("%ld\n", ft_strcspn(x, y));
// 	return (0);
// }