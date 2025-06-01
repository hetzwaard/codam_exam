#include <unistd.h>

int main (int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1), 0);
	
	int i = 0;
	int j = 0;
	int tab[256] = {0};
	
	while (av[1][i])
	{
		j = 0;
		while (av[2][j])
		{
			if (av[2][j] == av[1][i])
			{
				if (tab[(int)av[1][i]] == 0)
				{
					tab[(int)av[1][i]] = 1;
					write(1, &av[2][j], 1);
				}
			}
			j++;
		}
		i++;
	}
	return (write(1, "\n", 1), 0);
}