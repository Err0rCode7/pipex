/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:51:13 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 15:49:17 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_get_word_cnt(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			++count;
		++s;
	}
	return (count);
}

static char		*ft_getword(char const *s, char c, size_t *offset)
{
	char const	*start;
	char const	*last;
	char		*result;

	while (*(s + *offset) != '\0' && *(s + *offset) == c)
		++(*offset);
	start = s + *offset;
	while (*(s + *offset) != '\0' && *(s + *offset) != c)
		++(*offset);
	last = s + *offset;
	if ((result = ft_calloc(last - start + 1, sizeof(char))) == NULL)
		return (NULL);
	ft_strlcpy(result, start, last - start + 1);
	return (result);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str;
	size_t	count;
	size_t	index;
	size_t	offset;

	if (s == NULL)
		return (NULL);
	count = ft_get_word_cnt(s, c);
	if ((strs = ft_calloc(count + 1, sizeof(char *))) == NULL)
		return (NULL);
	index = 0;
	offset = 0;
	while (index < count)
	{
		if ((str = ft_getword(s, c, &offset)) == NULL)
		{
			while (index > 0)
				free(*(strs + --index));
			free(strs);
			return (NULL);
		}
		*(strs + index++) = str;
	}
	return (strs);
}
