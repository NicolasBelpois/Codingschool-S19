/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:25:56 by nbelpois          #+#    #+#             */
/*   Updated: 2018/06/25 10:00:14 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*link;

	if (!lst)
		return (NULL);
	link = f(lst);
	new = link;
	while (lst->next)
	{
		lst = lst->next;
		if (!(link->next = f(lst)))
			return (NULL);
		else
			link = link->next;
	}
	return (new);
}
