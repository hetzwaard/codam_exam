#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	safe(int *g, int x, int y)
{
	int	prev = 0;

	while (prev < x)
	{
		if (g[prev] == y)
			return (0);
		if (absolute(g[prev] - y) == x - prev)
			return (0);
		prev++;
	}
	return (1);
}

void	print(int *g, int n)
{
	int	i = 0;
	while (i < n)
	{
		fprintf(stdout, "%d", g[i]);
		if (i < n - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

void	solve(int *g, int x, int n)
{
	int	y = 0;
	if (x == n)
	{
		print(g, n);
		return ;
	}
	while (y < n)
	{
		if (safe(g, x, y))
		{
			g[x] = y;
			solve(g, x + 1, n);
		}
		y++;
	}
}

int	 main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int	n = atoi(argv[1]);
	int	*g = malloc(sizeof(int) * n);
	solve(g, 0, n);
	return (free(g), 0);
}
