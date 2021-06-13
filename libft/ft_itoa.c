/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:30:37 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 14:58:01 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_getsize(long long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		++size;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		++size;
	}
	++size;
	return (size);
}

char			*ft_itoa(int n)
{
	size_t		size;
	long long	ll_n;
	char		*result;

	ll_n = n;
	size = ft_getsize(ll_n);
	if ((result = ft_calloc(size + 1, sizeof(char))) == NULL)
		return (NULL);
	if (ll_n < 0)
	{
		ll_n *= -1;
		*result = '-';
	}
	while (ll_n / 10 > 0)
	{
		*(result + --size) = ll_n % 10 + '0';
		ll_n /= 10;
	}
	*(result + --size) = ll_n + '0';
	return (result);
}
