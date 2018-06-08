/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:48:01 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/08 16:48:03 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **list, void *content, size_t size)
{
	t_list *listbegin;

	listbegin = *list;
	if (listbegin)
	{
		while (listbegin->next)
			listbegin = listbegin->next;
		listbegin->next = ft_lstnew(content, size);
	}
	else
		*list = ft_lstnew(content, size);
}
