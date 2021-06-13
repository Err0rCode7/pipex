/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 20:35:32 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 22:21:49 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	cur = *lst;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
