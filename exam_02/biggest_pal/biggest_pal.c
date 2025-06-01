#include <unistd.h>

int	is_palindrome(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] != str[end])
			return (0);
		start++;
		end--;
	}
	return (1);
}

void	longest_palindrome(char *str)
{
	int i = 0;
	int j;
	int start_index = 0;
	int max_len = 0;

	//loop over all possible start positions of the palidrome
	while (str[i])
	{
		j = i;
		//loop over all possible end positons of the palindrome
		while (str[j])
		{
			if (is_palindrome(str, i, j) && (j - i + 1 > max_len))
			{
				max_len = j - i + 1;
				start_index = i;
			}
			j++;
		}
		i++;
	}
	write(1, &str[start_index], max_len);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		longest_palindrome(argv[1]);
	write(1, "\n", 1);
	return (0);
}
