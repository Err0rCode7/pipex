/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:05:48 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 18:40:53 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0 || s1 == s2)
		return (0);
	if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (n && *s1 && *s1 == *s2)
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
