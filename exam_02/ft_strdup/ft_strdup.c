char	*ft_strdup(char *src)
{
	int i = 0;
	int len = 0;
	char *str;

	while (src[len])
		len++;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
