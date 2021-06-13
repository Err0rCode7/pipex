/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:35:58 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/27 13:03:49 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*result;

	if (s == NULL)
		return (NULL);
	if ((result = ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	if (len == 0)
		return (result);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (result);
	len = start + len <= len_s ? len : len_s - start;
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
