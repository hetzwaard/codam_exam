#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int ac, char **av)
{
	int i;
	int nb1;
	int nb2;
	char c;

	if (ac != 4)
		return (write(1, "\n", 1), 0);

	nb1 = atoi(av[1]);
	c = av[2][0];
	nb2 = atoi(av[3]);

	if (c == '*')
		printf("%d\n", nb1 * nb2);
	else if (c == '/')
		printf("%d\n", nb1 / nb2);
	else if (c == '+')
		printf("%d\n", nb1 + nb2);
	else if (c == '-')
		printf("%d\n", nb1 - nb2);
	else if (c == '%')
		printf("%d\n", nb1 % nb2);
	return (0);
}