/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:37:53 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 21:17:55 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (*big != '\0' && n-- >= little_len)
	{
		if (*big == *little && ft_memcmp(big, little, little_len) == 0)
			return ((char *)big);
		++big;
	}
	return (NULL);
}
