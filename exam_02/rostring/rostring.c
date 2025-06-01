#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// " la      lumiere soit et la lumiere fut
// we already have skipped white spaces.
// we'll try to go thru the first word
// then use skip_white_spaces again.
// then write whole string
// then write first word.

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
char *get_first_word(int st, char *string)
{
	char *first_word;
	int i = st;
	int start;
	int len = 0;
	int	k = 0;

	start = i;
	while (string[i] && string[i] != '\t' && string[i] != ' ')
	{
		i++;
		len++;
	}
	first_word = malloc(sizeof(char) * len + 1);
	while (k < len)
	{
		first_word[k] = string[start];
		k++;
		start++;
	}
	first_word[k] = '\0';
	return(first_word);
	
}

void print_rest(int start, char *str)
{
	int i = start;
	int success = 0;

	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t') 
					&& (str[i + 1] == '\t'|| str[i + 1] == ' '))
			i++;
		if (str[i] == ' ' && !str[i + 1])
			i++;
		if (success == 0)
			success = 1;
	}
	if (success == 1)
		write(1, " ", 1);
}
void print_last_word(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
int main(int argc, char *argv[])
{
	char *first_word;
	char *string;
	int	i = 0;

	if (argc < 2) 
		return (0);
	string = argv[1];
	while (string[i] && (string[i] == ' ' || string[i] == '\t'))
		i++;
	first_word = get_first_word(i, string);
	while (string[i] && (string[i] == ' ' || string[i] == '\t'))
		i++;
	print_rest(ft_strlen(first_word) + i, string);
	print_last_word(first_word);
	write(1, "\n", 1);
}