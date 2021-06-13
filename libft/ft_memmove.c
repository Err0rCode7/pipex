/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:32:45 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/22 17:19:13 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cur;
	const unsigned char	*value;

	if (dest == src || n == 0)
		return (dest);
	if (dest > src)
	{
		cur = dest + n - 1;
		value = src + n - 1;
		while (n--)
			*cur-- = *value--;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
