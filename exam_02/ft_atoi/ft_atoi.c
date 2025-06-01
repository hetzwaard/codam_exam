int	ft_atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	int res;

	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32) && str[i])
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

//#include <stdio.h>
//#include <stdlib.h>

//int main(void)
//{
//	const char *str = " 213213215 521 521 521 5";
//	printf("%d\n", ft_atoi(str));
//	printf("%d\n", atoi(str));
//}