#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0; while (str[i]) i++; return (i);
}

void	perm(int *cnt, int n, int depth, char *buf)
{
	int	c = 0;

	if (depth == n)
	{
		buf[n] = '\0';
		puts(buf);
		return;
	}
	while (c < 256)
	{
		if (cnt[c])
		{
			buf[depth] = c;
			--cnt[c];
			perm(cnt, n, depth + 1, buf);
			++cnt[c];
		}
		c++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2 && av[1][0])
	{
		int		n = ft_strlen(av[1]);
		int		cnt[256] = {0};
		char	*buf = malloc(n + 1);
		int		i = 0;
		while (i < n)
			++cnt[av[1][i++]];
		perm(cnt, n, 0, buf);
		free(buf);
	}
	return 0;
}
