/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:39:31 by dlyubich          #+#    #+#             */
/*   Updated: 2017/10/31 18:39:33 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int a;

	a = 0;
	while (s[a] != '\0')
		a++;
	if (!a)
		return (NULL);
	while (a >= 0)
	{
		if (s[a] == (char)c)
			return ((char*)&s[a]);
		a--;
	}
	return (NULL);
}
