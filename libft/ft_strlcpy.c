/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:00:23 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/27 13:25:00 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	if (size > 0 && dest != NULL)
	{
		while (i + 1 < size && *(src + i))
		{
			*(dest + i) = *(src + i);
			++i;
		}
		*(dest + i) = '\0';
	}
	while (*(src + i) != '\0')
		i++;
	return (i);
}
