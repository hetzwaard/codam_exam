#include <stdio.h>
#include <stdlib.h>

void	print_subset(int *subset, int size)
{
	int i = 0;
	while (i < size)
	{
		if (i > 0)
			printf(" ");
		printf("%d", subset[i]);
		i++;
	}
	printf("\n");
}

void	backtrack(int *arr, int n, int target, int idx, int *subset, int sub_size, int sum)
{
	if (idx == n)
	{
		if (sum == target)
			print_subset(subset, sub_size);
		return ;
	}
	backtrack(arr, n, target, idx + 1, subset, sub_size, sum);
	subset[sub_size] = arr[idx];
	backtrack(arr, n, target, idx + 1, subset, sub_size + 1, sum + arr[idx]);
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
	backtrack(arr, n, target, 0, subset, 0, 0);
	return (free(arr), free(subset), 0);
}
