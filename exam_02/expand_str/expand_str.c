#include <unistd.h>

int main(int ac, char *av[])
{
	int i = 0;
	int j = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			if (av[1][i] == '\0')
				break;
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			{
				write(1, &av[1][i], 1);
				i++;
			}
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			if (av[1][i] != '\0')
				write(1, "   ", 3);
		}
	}
	write(1, "\n", 1);
	return (0);
}