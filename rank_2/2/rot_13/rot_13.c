#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 2 || av[1] == NULL)
		return (write(1, "\n",1 ), 0);
	int i = 0;
	char c;
	while (av[1][i] != '\0')
	{
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
		{
			c = av[1][i];
			if (c >= 'n')
				c -= 26;
			c += 13;
			write(1, &c, 1);
		}
		else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			c = av[1][i];
			if (c >= 'N')
				c -= 26;
			c += 13;
			write(1, &c, 1);
		}
		else
		{
			c = av[1][i];
			write(1, &c, 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}