/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:59:31 by seujeon           #+#    #+#             */
/*   Updated: 2021/06/16 01:16:13 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		ft_split_and_set(int fd, char **line, char *fd_buf[], int index)
{
	char	*pre_buf;
	char	*head;
	char	*tail;

	pre_buf = fd_buf[fd];
	if ((head = ft_strndup_gn(pre_buf, index)) == NULL)
		return (0);
	if ((tail = ft_strndup_gn(pre_buf + index + 1,
						ft_strlen_gn(pre_buf) - index - 1)) == NULL)
	{
		free(head);
		return (0);
	}
	fd_buf[fd] = tail;
	*line = head;
	free(pre_buf);
	return (FLAG_SUCCESS);
}

static int		ft_split_and_stack(char **fd_buf, char **line, char *buf,
									t_size size)
{
	if ((*line = ft_strjoin_gn(*line, ft_strndup_gn(buf, size.index))) == NULL)
	{
		free(buf);
		return (FLAG_FAIL);
	}
	if ((*fd_buf = ft_strndup_gn(buf + size.index + 1, size.len - size.index - 1))
				== NULL)
	{
		free(*line);
		*line = NULL;
		return (FLAG_FAIL);
	}
	free(buf);
	return (FLAG_SUCCESS);
}

static int		ft_process(char **fd_buf, char **line, char *buf, t_size size)
{
	if (size.len < 0)
	{
		free(buf);
		return (FLAG_FAIL);
	}
	if ((size.index = check_newline(buf)) >= 0)
		return (ft_split_and_stack(fd_buf, line, buf, size));
	if ((*line = ft_strjoin_gn(*line, ft_strndup_gn(buf, size.len))) == NULL)
		return (FLAG_FAIL);
	*fd_buf = *line;
	if (size.len < BUFFER_SIZE)
	{
		*fd_buf = NULL;
		free(buf);
		return (FLAG_EOF);
	}
	return (NEXT);
}

static int		ft_process_eof(char *buf, char **line, char **fd_buf)
{
	free(buf);
	if (*line != NULL)
		*fd_buf = NULL;
	else
	{
		if ((*line = ft_strndup_gn("", 0)) == NULL)
			return (FLAG_FAIL);
		*fd_buf = NULL;
	}
	return (FLAG_EOF);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*fd_buf[OPEN_MAX];
	t_size		size;

	if (fd < 0 || fd >= OPEN_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = fd_buf[fd];
	if (*line != NULL && ((size.index = check_newline(*line)) >= 0))
	{
		if (ft_split_and_set(fd, line, fd_buf, size.index))
			return (FLAG_SUCCESS);
		else
			return (FLAG_FAIL);
	}
	if ((buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))) == NULL)
		return (FLAG_FAIL);
	while ((size.len = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (size.len > 0)
			*(buf + size.len) = '\0';
		if ((size.ret = ft_process(&fd_buf[fd], line, buf, size)) != NEXT)
			return (size.ret);
	}
	return (ft_process_eof(buf, line, &fd_buf[fd]));
}
