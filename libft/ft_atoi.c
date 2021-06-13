/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:59:11 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 23:09:08 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == ' ' ||
			c == '\f' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	unsigned long long	result;
	int					is_negative;

	result = 0;
	is_negative = 0;
	while (*nptr != '\0' && ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_negative = 1;
		++nptr;
	}
	while (*nptr != '\0' && *nptr == '0')
		++nptr;
	while (*nptr != '\0' && *nptr >= '0' && *nptr <= '9'
		&& result <= MIN_ULL)
		result = result * 10 + *nptr++ - '0';
	if (result > MAX_ULL && !is_negative)
		return (-1);
	else if (result > MIN_ULL && is_negative)
		return (0);
	return (is_negative ? -1 * (long long)result : (long long)result);
}
