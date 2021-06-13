/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:47:37 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/26 12:18:37 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = (char *)s;
	while (*start != '\0')
		++start;
	while (start - s >= 0)
	{
		if (*start == (unsigned char)c)
			return ((char *)start);
		--start;
	}
	return (NULL);
}
