/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:25:25 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 18:45:19 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*cur;
	const unsigned char	*value;

	if (n == 0)
		return (NULL);
	cur = (unsigned char *)dest;
	value = (const unsigned char *)src;
	while (n--)
	{
		*cur++ = *value++;
		if ((unsigned char)c == *(value - 1))
			return (cur);
	}
	return (NULL);
}
