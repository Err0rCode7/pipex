#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

typedef struct		s_cmd
{
	const char		*cmd[6];
	char * const	*argv;
	char * const	*envp;
}					t_cmd;

typedef struct		s_pipe
{
	int			argc;
	char const	**av;
	int			status;
	int			index;
	int			index_i;
	pid_t		pid;
	int			*pipefd;
	t_cmd		cmd_arg;
}					t_pipe;

# define CHILD 0

extern char		**environ;

int				redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return(-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int				redirect_out(const char *file)
{
	int fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static void		connect_pipe(int pipefd[2], int io)
{
	dup2(pipefd[io], io);
	close(pipefd[0]);
	close(pipefd[1]);
}

static void		cmd_init(const char *cmd, t_cmd *strt)
{
	char **chunk;

	chunk = ft_split(cmd, ' ');
	strt->cmd[0] = ft_strjoin("/bin/", chunk[0]);
	strt->cmd[1] = ft_strjoin("/usr/local/bin/", chunk[0]);
	strt->cmd[2] = ft_strjoin("/usr/bin/", chunk[0]);
	strt->cmd[3] = ft_strjoin("/usr/sbin/", chunk[0]);
	strt->cmd[4] = ft_strjoin("/sbin/", chunk[0]);
	strt->cmd[5] = 0;
	strt->argv = (char *const *)chunk;
	strt->envp = NULL;
}

static void		run_cmd(const char *cmd, t_cmd *cmd_arg)
{
	int i;

	i = 0;
	cmd_init(cmd, cmd_arg);
	while(i < 5)
		execve(cmd_arg->cmd[i++], cmd_arg->argv, environ);
	perror(cmd_arg->argv[0]);
	exit(1);
}

static void		close_pre_pipes(int count, t_pipe *pipe_var)
{
	int i;

	i = 0;
	while (i < count)
	{
		close(pipe_var->pipefd[pipe_var->argc - 2 - i]);
		close(pipe_var->pipefd[pipe_var->argc - 2 - i]);
		i++;
	}
}

int				run_child(t_pipe *pipe_vars)
{
	pid_t	pid;

	if (pipe_vars->index == 2)
	{
		close_pre_pipes(pipe_vars->argc - 2, pipe_vars);
		redirect_in(pipe_vars->av[pipe_vars->index - 1]);
		connect_pipe(pipe_vars->pipefd, STDOUT_FILENO);
		run_cmd(pipe_vars->av[pipe_vars->index], &pipe_vars->cmd_arg);
	}
	else if (pipe_vars->index > 2)
	{
		if ((pid = fork()) < 0)
			exit(1);
		if (pid > 0)
		{
			waitpid(pid, &pipe_vars->status, 0);
			if (WIFEXITED(pipe_vars->status) == 0)
				exit(1);
			close_pre_pipes(pipe_vars->index - 2, pipe_vars);
			connect_pipe(pipe_vars->pipefd + (pipe_vars->index) * 2, STDIN_FILENO);
			connect_pipe(pipe_vars->pipefd + (pipe_vars->index) * 2, STDOUT_FILENO);
			run_cmd(pipe_vars->av[pipe_vars->index], &pipe_vars->cmd_arg);
		}
		else if (pid == CHILD)
		{
			pipe_vars->index -= 1;
			run_child(pipe_vars);
		}
	}
	return (1);
}

int				main(int argc, char const *argv[])
{
	t_pipe	pipe_vars;
	int		*pipe_fd;
	int		i;

	if (argc < 4)
		return (0);
	pipe_vars.argc = argc;
	pipe_vars.av = argv;
	pipe_vars.index = argc - 3;
	if ((pipe_vars.pid = fork()) < 0)
		exit(1);
	// pipe를 커맨드 개수만큼 만든다.
	pipe_vars.pipefd = malloc (2 * sizeof(int) * (argc - 3));
	i = 0;
	pipe_fd = pipe_vars.pipefd;
	while (i < argc - 2)
	{
		if (pipe(pipe_fd) < 0)
			pipe_fd += 2;
		i++;
	}
	if (pipe_vars.pid > 0)
	{
		waitpid(pipe_vars.pid, &pipe_vars.status, 0);
		if (WIFEXITED(pipe_vars.status) == 0)
			exit(1);
		redirect_out(argv[argc - 1]);
		connect_pipe(pipe_fd + (argc - 3) * 2, STDIN_FILENO);
		run_cmd(argv[argc - 2], &pipe_vars.cmd_arg);
	}
	else if (pipe_vars.pid == CHILD)
		run_child(&pipe_vars);
	return (0);
}