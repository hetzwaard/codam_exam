#include <unistd.h>
#include <stdlib.h>

// get the first word.
// print it at the end.
// fwi is now the end index of the first word.

// so my plan was that I would take the first word's index, (first and the last index)
// after getting those indexes, we could pass the word and start writing the string with 
// taking spaces into account. only one space between the words. we need take this into account.
// after writing a word, we pass all the spaces, and if we don't get null terminator, we just print " ".
// that plan seems like could work. Easy peasy.

int	main(int ac, char **av)
{
	if (ac < 2)
		return (write(1, "\n", 1), 0);

	int i = 0;
	int fw_f = 0;
	int fw_l = 0;
	char *str = av[1];
	
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	fw_f = i;
	while (str[i] && (str[i] != 9 || str[i] != 10 || str[i] != 11 || str[i] != 12 || str[i] != 13 || str[i] != 32))
		i++;
	fw_l = i;
	while (str[fw_f] != str[fw_l])
	{
		write(1, &str[fw_f], 1);
		fw_f++;
	}
	return (write(1, "\n", 1), 0);
}