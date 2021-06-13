/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:01:41 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/22 18:54:51 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	size = len + ft_strlen(s2) + 1;
	if ((result = ft_calloc(size, sizeof(char))) == NULL)
		return (NULL);
	ft_strlcpy(result, s1, size);
	ft_strlcpy(result + len, s2, size);
	return (result);
}
