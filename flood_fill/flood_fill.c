#include <stdbool.h>

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

void	ff(char **tab, t_point size, t_point dot, char fill)
{
	if (dot.x < 0 || dot.x >= size.x || dot.y < 0 || dot.y >= size.y ||
		tab[dot.y][dot.x] != fill)
		return ;
	tab[dot.y][dot.x] = 'F';
	ff(tab, size, (t_point){dot.x - 1, dot.y}, fill);
	ff(tab, size, (t_point){dot.x + 1, dot.y}, fill);
	ff(tab, size, (t_point){dot.x, dot.y - 1}, fill);
	ff(tab, size, (t_point){dot.x, dot.y + 1}, fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	ff(tab, size, begin, tab[begin.y][begin.x]);
}
