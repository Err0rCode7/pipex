/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:18:44 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/26 12:19:15 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_isinset(int c, char const *set)
{
	while (*set)
	{
		if ((unsigned char)c == *set)
			return (1);
		++set;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	char const	*end;
	size_t		len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || *set == '\0')
		return (ft_strdup(s1));
	while (*s1 && ft_isinset(*s1, set))
		++s1;
	end = s1 + ft_strlen(s1) - 1;
	while (s1 <= end && ft_isinset(*end, set))
		--end;
	len = end - s1 + 1;
	if ((result = ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len + 1);
	return (result);
}
