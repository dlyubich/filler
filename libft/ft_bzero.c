/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:20:47 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/01 16:20:50 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long i;
	unsigned char *new;

	i = 0;
	new = (unsigned char*)s;
	while (i < n)
	{
		new[i] = 0;
		i++;
	}
}
