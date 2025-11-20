#include <unistd.h>
#include <stdio.h>

int check(char *a)
{
	int b = 0;
	int c = 0;
	while (a[b])
	{
		if (a[b] == '(')
			c++;
		if (a[b] == ')')
		{
			if (c)
				c--;
			else
				return 0;
		}
		b++;
	}
	return c == 0;
}

int need(char *a)
{
	int b = 0;
	int c = 0;
	int d = 0;
	while (a[b])
	{
		if (a[b] == '(')
			c++;
		if (a[b] == ')')
		{
			if (c)
				c--;
			else
				d++;
		}
		b++;
	}
	return c + d;
}

void solve(char *a, int b, int c, int d)
{
	if (b == d)
	{
		if (check(a))
			puts(a);
			return;
	}
	for (int i = c; a[i]; i++)
	{
		char e = a[i];
		if (e == '(' || e == ')')
		{
			a[i] = ' ';
			solve(a, b + 1, i + 1, d);
			a[i] = e;
		}
	}
}

int main(int ac, char **av)
{
		if (ac == 2)
		solve(av[1], 0, 0, need(av[1]));
}
