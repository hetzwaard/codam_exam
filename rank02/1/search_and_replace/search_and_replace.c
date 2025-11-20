#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 4)
		return((write(1, "\n", 1)), 0);
	if (argv[2][1] != '\0' || argv[3][1] != '\0')
		return((write(1, "\n", 1)), 0);
	int i = 0;
	while (argv[1][i] != '\0')
	{
		if(argv[1][i] == argv[2][0])
			argv[1][i] = argv[3][0];
		write(1, &argv[1][i], 1);
		i++;
	}
	return((write(1, "\n", 1)), 0);
}