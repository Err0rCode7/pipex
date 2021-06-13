/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:05:05 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/22 19:10:54 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long		ll_n;
	unsigned int	i;
	char			buf[11];

	ll_n = n;
	if (ll_n < 0)
	{
		ft_putchar_fd('-', fd);
		ll_n *= -1;
	}
	i = 10;
	*(buf + i--) = '\0';
	while (ll_n / 10 > 0)
	{
		*(buf + i--) = ll_n % 10 + '0';
		ll_n /= 10;
	}
	buf[i] = ll_n + '0';
	ft_putstr_fd(buf + i, fd);
}
