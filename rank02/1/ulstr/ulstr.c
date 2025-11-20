#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;
	char c;
	if (ac != 2)
		return (write(1, "\n", 1 ), 0);
	while (av[1][i] != '\0')
	{
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
		{
			c = av[1][i];
			c -= 32;
			write(1, &c, 1);
		}
		else if(av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			c = av[1][i];
			c += 32;
			write(1, &c, 1);
		}
		else
		{
			c = av[1][i];
			write(1, &c, 1);
		}
		i++;
	}
	return (write(1, "\n", 1), 0);
}