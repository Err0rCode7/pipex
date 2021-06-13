/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:19:57 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 16:43:55 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cur;
	const unsigned char	*value;

	if (dest == src || n == 0)
		return (dest);
	cur = (unsigned char*)dest;
	value = src;
	while (n--)
		*cur++ = *value++;
	return (dest);
}
