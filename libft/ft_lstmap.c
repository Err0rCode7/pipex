/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 20:40:52 by seujeon           #+#    #+#             */
/*   Updated: 2020/12/23 21:42:01 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*new;
	t_list	*result;

	if (lst == NULL)
		return (NULL);
	cur = lst;
	new = NULL;
	result = NULL;
	while (cur)
	{
		if ((new = ft_lstnew(f(cur->content))) == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		cur = cur->next;
	}
	return (result);
}
