#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 2)
		return(write(1, "\n", 1), 0);
	int i = 0;
	while (av[1][i])
	{
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
		{
			av[1][i] = ('m' - (av[1][i] - 'n'));
			write(1, &av[1][i], 1);
		}
		else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			av[1][i] = ('M' - (av[1][i] - 'N'));
			write(1, &av[1][i], 1);
		}
		else
			write(1, &av[1][i], 1);
		i++;
	}
	return (write(1, "\n", 1), 0);
}
