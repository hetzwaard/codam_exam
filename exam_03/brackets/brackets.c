#include <unistd.h>

#define OPEN_PAN '('
#define CLOSED_PAN ')'
#define OPEN_SQU '['
#define CLOSED_SQU ']'
#define OPEN_CUR '{'
#define CLOSED_CUR '}'

int	is_open(int c)
{
	return (c == OPEN_PAN || c == OPEN_SQU || c == OPEN_CUR);
}

int	is_closed(int c)
{
	return (c == CLOSED_PAN || c == CLOSED_SQU || c == CLOSED_CUR);
}

int	matching(char *str)
{
	int	stack[1000];
	int	top = 0;
	int	i = 0;

	while (str[i])
	{
		if (is_open(str[i]))
			stack[top++] = str[i];
		else if (is_closed(str[i]))
		{
			if (top == 0
			|| (str[i] == OPEN_PAN && stack[top] != CLOSED_PAN)
			|| (str[i] == OPEN_SQU && stack[top] != CLOSED_SQU)
			|| (str[i] == OPEN_CUR && stack[top] != CLOSED_CUR))
				return (0);
			else
				top--;
		}
		i++;
	}
	return (1);
}

void	parse(char **argv)
{
	int i = 1;
	while (argv[i])
	{
		if (matching(argv[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		parse(argv);
	else
		write(1, "\n", 1);
	return (0);
}