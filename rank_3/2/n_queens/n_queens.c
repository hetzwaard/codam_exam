#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	safe(int *g, int x, int y)
{
	int prev = 0;
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

void	print(int n, int *g)
{
	int i = 0;
	while(i < n)
	{
		fprintf(stdout, "%d", g[i]);
		if (i < n - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

void	solve(int n, int *g, int x, int y)
{
	if (x == n)
	{
		print(n, g);
		return ;
	}
	y = 0;
	while(y < n)
	{
		if (safe(g, x, y))
		{
			g[x] = y;
			solve(n, g, x + 1, y);
		}
		y++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int n = atoi(av[1]);
	int *g = malloc(n * 4);
	solve(n, g, 0, 0);
	return (free(g), 0);
}