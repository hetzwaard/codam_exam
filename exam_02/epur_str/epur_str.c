#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	int i = 0;
	while (av[1][i] == ' ' || av[1][i] == '\t')
		i++;
	while (av[1][i])
	{
		if (av[1][i] == ' ' || av[1][i] == '\t')
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			if (av[1][i] == '\0' || av[1][i + 1] == '\0')
				return (write(1, "\n", 1), 0);
			write(1, " ", 1);
		}
		if (av[1][i] >= 32 && av[1][i] <= 126)
			write(1, &av[1][i], 1);
		i++;
	}
	return (write(1, "\n", 1), 0);
}
