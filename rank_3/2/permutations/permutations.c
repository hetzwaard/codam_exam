#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	perm(int *count, int len, char *buffer, int depth)
{
	int c = 0;

	if (depth == len)
	{
		buffer[len] = '\0';
		puts(buffer);
		return ;
	}
	while (c < 256)
	{
		if (count[c])
		{
			buffer[depth] = c;
			--count[c];
			perm(count, len, buffer, depth + 1);
			++count[c];
		}
		c++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);

	int count[256] = {0};
	int len = ft_strlen(av[1]);
	char *buffer = malloc(len + 1);

	int i = 0;
	while (i < len)
		++count[av[1][i++]];
	perm(count, len, buffer, 0);
	return (free(buffer), 0);
}