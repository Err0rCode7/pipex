#include "pipe.h"

static void		connect_pipe(int pipefd[2], int io)
{
	dup2(pipefd[io], io);
	close(pipefd[0]);
	close(pipefd[1]);
}

int				here_doc(t_pipe *pipe_vars)
{
	char	*line;
	int		*pipefd;

	pipefd = pipe_vars->pipefd + (pipe_vars->pipe_index + 1) * 2;
	if (pipe(pipefd) == -1)
		exit(1);
	while (1)
	{
		write(STDOUT_FILENO, "here_doc> ", 10);
		if (get_next_line(STDIN_FILENO, &line) < 0)
			exit(1);
		if (ft_strncmp(pipe_vars->av[2], line,
						ft_strlen((char *)pipe_vars->av[2]) + 1) == 0)
			break ;
		close(pipefd[STDOUT_FILENO]);
		write(STDOUT_FILENO, line, ft_strlen(line));
		write(pipefd[STDIN_FILENO], line, ft_strlen(line));
		free(line);
	}
	free(line);
	connect_pipe(pipefd, STDIN_FILENO);
	return (1);
}

int				redirect_in(const char *file, t_pipe *pipe_vars)
{
	int fd;

	if (pipe_vars->is_double_redirection)
		return (here_doc(pipe_vars));
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

int				redirect_out(const char *file, t_pipe *pipe_vars)
{
	int fd;

	if (!pipe_vars->is_double_redirection)
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
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
		execve(cmd_arg->cmd[i++], cmd_arg->argv, cmd_arg->envp);
	perror(cmd_arg->argv[0]);
	exit(1);
}

int				run_child(t_pipe *pipe_vars)
{
	pid_t	pid;

	if (pipe_vars->index == 2 + pipe_vars->is_double_redirection)
	{
		redirect_in(pipe_vars->av[pipe_vars->index - 1], pipe_vars);
		connect_pipe(pipe_vars->pipefd + pipe_vars->pipe_index * 2, STDOUT_FILENO);
		run_cmd(pipe_vars->av[pipe_vars->index], &pipe_vars->cmd_arg);
	}
	else if (pipe_vars->index > 2 + pipe_vars->is_double_redirection)
	{
		if (pipe(pipe_vars->pipefd + ++pipe_vars->pipe_index * 2) == -1)
			exit(1);
		if ((pid = fork()) < 0)
			exit(1);
		if (pid > 0)
		{
			waitpid(pid, &pipe_vars->status, 0);
			if (WIFEXITED(pipe_vars->status) == 0)
				exit(1);
			connect_pipe(pipe_vars->pipefd + (pipe_vars->pipe_index - 1) * 2, STDOUT_FILENO);
			connect_pipe(pipe_vars->pipefd + pipe_vars->pipe_index * 2, STDIN_FILENO);
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

// cmd << test | cmd >> out

void			proc_pipe(t_pipe pipe_vars)
{
	if (!(pipe_vars.pipefd = malloc(2 * sizeof(int) *
		(pipe_vars.argc - 4))))
		exit(1);
	if (pipe(pipe_vars.pipefd) == -1)
		exit(1);
	if ((pipe_vars.pid = fork()) < 0)
		exit(1);
	if (pipe_vars.pid > 0)
	{
		waitpid(pipe_vars.pid, &pipe_vars.status, 0);
		if (WIFEXITED(pipe_vars.status) == 0)
		{
			printf("exit\n");
			exit(1);
		}
		redirect_out(pipe_vars.av[pipe_vars.argc - 1], &pipe_vars);
		connect_pipe(pipe_vars.pipefd, STDIN_FILENO);
		run_cmd(pipe_vars.av[pipe_vars.argc - 2], &pipe_vars.cmd_arg);
	}
	else if (pipe_vars.pid == CHILD)
	{
		pipe_vars.index -= 1;
		run_child(&pipe_vars);
	}
}

int				main(int argc, char const *argv[])
{
	t_pipe	pipe_vars;

	pipe_vars.argc = argc;
	pipe_vars.av = argv;
	pipe_vars.index = argc - 2;
	pipe_vars.pipe_index = 0;
	pipe_vars.is_double_redirection = 0;
	if (argc < 4)
		return (0);
	if ((ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc") + 1)) == 0)
		pipe_vars.is_double_redirection = 1;
	proc_pipe(pipe_vars);
	return (0);
}