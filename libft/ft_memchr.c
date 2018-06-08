/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:51:24 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/01 17:51:25 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	int				a;

	a = 0;
	d = (unsigned char*)s;
	while (n != 0)
	{
		if (d[a] == (unsigned char)c)
			return (&d[a]);
		else
		{
			a++;
			n--;
		}
	}
	return (NULL);
}
