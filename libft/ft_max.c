/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:09:38 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/08 18:09:39 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int *s, size_t len)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	tmp = 0;
	while (i < len)
	{
		if (i < (len - 1) && s[i] > s[i + 1])
		{
			tmp = s[i];
			s[i] = s[i + 1];
			s[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (s[len - 1]);
}