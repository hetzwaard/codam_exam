#include <unistd.h>

int	match(char a, char b)
{
	return	(a == '(' && b == ')' ||
				 a == '[' && b == ']' ||
				 a == '{' && b == '}');
}

int	checker(char *av)
{
	int i = 0;
	int stack[10000];
	int top = 0;

	while (av[i])
	{
		if (av[i] == '(' || av[i] == '[' || av[i] == '{')
			stack[top++] = av[i];
		if (av[i] == ')' || av[i] == ']' || av[i] == '}')
			if (!match(stack[--top], av[i]))
				return (0);
		i++;
	}
	return (!top);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (write(1, "\n", 1), 0);
	int i = 1;
	while (i < ac)
	{
		if (checker(av[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
}