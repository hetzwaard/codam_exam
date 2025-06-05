#include <unistd.h>

// first, take the first and the last index of the first word
// then start printing from the first index of the second word
// pass the white spaces and there should be only one space between words
// at the end, print the first word.

int	main(int ac, char **av)
{
	if (ac < 2)
		return(write(1, "\n", 1), 0);

	int i = 0;
	int fw_f = 0;
	int fw_l = 0;
	int flag = 0;
	char *str = av[1];

	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	fw_f = i;
	while (str[i] && (str[i] != ' ' || str[i] != '\t'))
		i++;
	fw_l = i;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		if (str[i] == ' ' || str[i] == '\t')
		{
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
			write(1, " ", 1);
		}
		else if (str[i] == '\0')
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 1)
		write(1, " ", 1);
	while (str[fw_f] != str[fw_l])
		write(1, &str[fw_f++], 1);
	return(write(1, "\n", 1), 0);
}
