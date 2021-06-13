/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:23:06 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 19:13:01 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s);
	if ((result = (char *)ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	ft_strlcpy(result, s, len + 1);
	return (result);
}
