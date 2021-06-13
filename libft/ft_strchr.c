/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:03:45 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/22 14:31:39 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*start;

	start = (char *)s;
	while (*start != c)
	{
		if (*start == '\0')
			return (NULL);
		++start;
	}
	return (start);
}
