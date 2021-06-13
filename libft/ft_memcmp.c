/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:21:26 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/22 14:29:17 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *a;
	const unsigned char *b;

	if (s1 == s2 || n == 0)
		return (0);
	a = s1;
	b = s2;
	while (n && *a == *b)
	{
		++a;
		++b;
		--n;
	}
	if (n == 0)
		return (0);
	return (*a - *b);
}
