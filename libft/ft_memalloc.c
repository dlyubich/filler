/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:58:24 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/02 15:58:26 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *el;

	el = (unsigned char*)malloc(size * (sizeof(unsigned char)));
	if (!el)
		return (NULL);
	ft_bzero(el, size);
	return (el);
}
