#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int	fd[2];
	int	p_fd = -1;
	pid_t	pid;
	int	i = 0;
	
	while (cmds[i])
	{
		int next = (cmds[i + 1] != 0);
		if (next && pipe(fd) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
		{
			if (next)
			{
				close(fd[0]);
				close(fd[1]);
			}
			return (1);
		}
		if (pid == 0)
		{
			if (p_fd != -1)
			{
				if (dup2(p_fd, STDIN_FILENO) == -1)
					exit(1);
				close(p_fd);
			}
			if (next)
			{
				close(fd[0]);
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (p_fd != -1)
			close(p_fd);
		if (next)
		{
			close(fd[1]);
			p_fd = fd[0];
		}
		i++;
	}
	while (wait(0) > 0)
		;
	return (0);
}
