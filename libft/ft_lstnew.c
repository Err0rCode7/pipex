/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:40:35 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 19:46:59 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	if ((res = (t_list *)malloc(sizeof(t_list) * 1)) == NULL)
		return (NULL);
	res->content = content;
	res->next = 0;
	return (res);
}
