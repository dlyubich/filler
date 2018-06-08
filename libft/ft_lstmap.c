/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:50:56 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/04 18:50:57 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *start;

	if (!lst)
		return (NULL);
	start = f(ft_lstnew(lst->content, lst->content_size));
	new = start;
	lst = lst->next;
	while (lst)
	{
		start->next = f(ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
		start = start->next;
	}
	start->next = NULL;
	return (new);
}
