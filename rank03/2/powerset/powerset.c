#include <stdlib.h>
#include <stdio.h>

void	print_subset(int *subset, int sub_size)
{
	int i = 0;
	while (i < sub_size)
	{
		if (i > 0)
			printf(" ");
		printf("%d", subset[i++]);
	}
	printf("\n");
}

void	backtrack(int target, int n, int *arr, int *subset, int sub_size, int index, int sum)
{
	if (index == n)
	{
		if (target == sum)
			print_subset(subset, sub_size);
		return ;
	}
	backtrack(target, n, arr, subset, sub_size, index + 1, sum);
	subset[sub_size] = arr[index];
	backtrack(target, n, arr, subset, sub_size + 1, index + 1, sum + arr[index]);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);

	int target = atoi(av[1]);
	int n = ac - 2;
	int *arr = malloc(n * 4);
	int *subset = malloc(n * 4);

	if (!arr || !subset)
		return (1);

	int i = 0;
	while (i < n)
	{
		arr[i] = atoi(av[i + 2]);
		i++;
	}
	backtrack(target, n, arr, subset, 0, 0, 0);
	return (free(arr), free(subset), 0);
}