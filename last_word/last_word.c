#include <unistd.h>

int main (int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	int i = 0;
	while (av[1][i])
		i++;
	i -= 1;
	while (av[1][i] == ' ' || av[1][i] == '\t')
		i--;
	while ((av[1][i] != ' ' && av[1][i] != '\t') && i >= 0)
		i--;
	i += 1;
	while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
		write(1, &av[1][i++], 1);
	return(write(1, "\n", 1), 0);
}

