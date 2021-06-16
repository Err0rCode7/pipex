#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line_bonus.h"

# define CHILD 0

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
	pid_t		pid;
	int			*pipefd;
	int			pipe_index;
	int			is_double_redirection;
	t_cmd		cmd_arg;
}					t_pipe;


// int				ft_strncmp(const char *s1, const char *s2, size_t n);
// char			**ft_split(char const *s, char c);


#endif