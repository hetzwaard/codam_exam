#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	safe(int *board, int column, int row)
{
	int	prev = 0;

	while (prev < column)
	{
		if (board[prev] == row)
			return (0);
		if (absolute(board[prev] - row) == column - prev)
			return (0);
		prev++;
	}
	return (1);
}

void	print(int *board, int n_queens)
{
	int	i = 0;
	while (i < n_queens)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < n_queens - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

void	solve(int *board, int column, int n_queens)
{
	int	row = 0;
	if (column == n_queens)
	{
		print(board, n_queens);
		return ;
	}
	while (row < n_queens)
	{
		if (safe(board, column, row))
		{
			board[column] = row;
			solve(board, column + 1, n_queens);
		}
		row++;
	}
}

int	 main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int	n_queens = atoi(argv[1]);
	int	*board = malloc(sizeof(int) * n_queens);
	solve(board, 0, n_queens);
	return (free(board), 0);
}
