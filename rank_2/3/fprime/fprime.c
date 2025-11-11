#include <stdio.h>
#include <stdlib.h>

void	fprime(unsigned int number)
{
	unsigned int	prime;
	if (number == 1)
		printf("1");
	else
	{
		prime = 2;
		while (number > 1)
		{
			if (number % prime == 0)
			{
				printf("%d", prime);
				number /= prime;
				if (number > 1)
					printf("*");
				prime--;
			}
			prime++;
		}
	}
}

int main (int ac, char **av)
{
	if (ac != 2)
		return (printf("\n"), 0);
	else if (*av[1] && av[1][0] == '-')
		return (printf("\n"), 0);
	else
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
