int		nbr_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) || \
	(c >= 'a' && c <= ('a' + base - 10)));
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		nbr;
	int		sign;

	if (!str[0] || (str_base < 2 || str_base > 16))
		return (0);
	i = 0;
    nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || \
		str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && nbr_inbase(str[i], str_base))
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			nbr = (nbr * str_base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'f')
			nbr = (nbr * str_base) + (str[i] - 'a' + 10);
		else
			nbr = (nbr * str_base) + (str[i] - '0');
		i += 1;
	}
	return (nbr * sign);
}
