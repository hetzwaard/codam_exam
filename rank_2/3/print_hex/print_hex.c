#include <unistd.h>

int	ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

void	print_hex(int number)
{
	if (number >= 16)
		print_hex(number / 16);
	number = number % 16;
	char c = "0123456789abcdef"[number];
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	print_hex(ft_atoi(av[1]));
	return (write(1, "\n", 1), 0);
}

