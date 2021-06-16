/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:03:58 by seujeon           #+#    #+#             */
/*   Updated: 2021/06/16 01:18:30 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc_gn(size_t len, size_t size)
{
	void	*res;
	size_t	index;

	if ((res = (void *)malloc(len * size)) == NULL)
		return (NULL);
	index = 0;
	while (index < len * size)
		*(char *)(res + index++) = '\0';
	return (res);
}

char	*ft_strndup_gn(char *str, size_t n)
{
	size_t	index;
	char	*res;

	if ((res = (char *)malloc((n + 1) * sizeof(char))) == NULL)
		return (NULL);
	index = 0;
	while (index < n && *str)
	{
		*(res + index) = *str++;
		++index;
	}
	*(res + index) = '\0';
	return (res);
}

size_t	ft_strlen_gn(char *str)
{
	char	*start;

	if (str == NULL)
		return (0);
	start = str;
	while (*start)
		++start;
	return (start - str);
}

char	*ft_strjoin_gn(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	index_res;
	size_t	index_s;
	char	*res;

	if (s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen_gn(s1);
	len_s2 = ft_strlen_gn(s2);
	index_res = 0;
	if ((res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char))) == NULL)
		return (NULL);
	index_s = 0;
	while (s1 != NULL && index_s < len_s1)
		*(res + index_res++) = *(s1 + index_s++);
	index_s = 0;
	while (index_s < len_s2)
		*(res + index_res++) = *(s2 + index_s++);
	*(res + index_res) = '\0';
	free(s1);
	free(s2);
	return (res);
}

ssize_t	check_newline(char *str)
{
	char *start;

	start = str;
	while (str - start < BUFFER_SIZE && *str)
	{
		if (*str == '\n')
			return (str - start);
		++str;
	}
	return (-1);
}
