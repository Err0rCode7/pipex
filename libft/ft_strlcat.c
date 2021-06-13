/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:17:47 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 14:49:23 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (*dest && i < size)
	{
		++dest;
		++i;
	}
	while (*src && i + 1 < size)
	{
		*dest++ = *src++;
		++i;
	}
	if (i < size)
		*dest = '\0';
	while (*src++)
		++i;
	return (i);
}
