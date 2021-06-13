/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:31:18 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/22 16:58:43 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *cur;

	if (n == 0)
		return (b);
	cur = (unsigned char *)b;
	while (n--)
	{
		*cur = (unsigned char)c;
		if (n)
			++cur;
	}
	return (b);
}
