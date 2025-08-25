// #include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


char	*get_next_line(int fd)
{
	char	*s = malloc(1000000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}

//int main(void)
//{
//	char *line;
//	int fd = open("text.txt", O_RDONLY);
//	while (1)
//	{
//		line = get_next_line(fd);
//		if (!line)
//			break ;
//		printf("%s", line);
//		free(line);
//	}
//	close(fd);
//	return (0);
//}