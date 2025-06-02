#include <stdlib.h>

char	**ft_split(char *str)
{
	char	**res;
	int i = 0;
	int j = 0;
	int k = 0;
	
	res = malloc(1000 * sizeof(char*));
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
		{
			res[k] = malloc(1000);
			j = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				res[k][j++] = str[i++];
			res[k++][j] = 0;
		}
	}
	res[k] = 0;
	return (res);
}

// #include <stdio.h>

// int main() {
//     char **arr = ft_split(" \n \t Hello  world  42 ");
//     for (int i = 0; arr[i]; i++)
//         printf("word[%d]: %s\n", i, arr[i]);
// }
