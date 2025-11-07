#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

char	*get_next_line(int fd)
{
	char *s = malloc(1000000), *c = s;
	int i = 0;
	while (BUFFER_SIZE >= i && *c != '\n')
	{
		read(fd, c, BUFFER_SIZE);
		if (*c == '\0')
		{
			i++;
			break ;
		}
		c += BUFFER_SIZE;
	}
	return c > s ? (*c = 0, s) : (free(s), NULL);
}

// int main(void)
// {
// 	char *line;
// 	int fd = open("text.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
