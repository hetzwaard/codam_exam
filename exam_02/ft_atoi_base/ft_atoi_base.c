int	get_digit_value(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return -1;
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int res = 0;
	int sign = 1;
	int digit;

	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str_base < 2 || str_base > 16)
		return 0;
	while (str[i])
	{
		digit = get_digit_value(str[i]);
		if (digit == -1 || digit >= str_base)
			break ;
		res = res * str_base + digit;
		i++;
	}
	return (res * sign);
}
