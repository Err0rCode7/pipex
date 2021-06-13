/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:49:48 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/27 13:04:20 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((result = ft_calloc(ft_strlen(s) + 1, sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(result + i) = f(i, *(s + i));
		++i;
	}
	return (result);
}
