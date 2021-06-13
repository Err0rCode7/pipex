/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:12:51 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 14:44:49 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *cur;

	cur = s;
	while (n--)
	{
		if (*cur == (unsigned char)c)
			return ((void *)cur);
		++cur;
	}
	return (NULL);
}
