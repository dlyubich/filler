/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:31:06 by dlyubich          #+#    #+#             */
/*   Updated: 2017/10/31 17:31:07 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int i;
	unsigned int a;

	i = 0;
	a = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[a] && len)
	{
		i = 0;
		while ((little[i] == big[a + i]) && ((len - 1) >= (i)))
		{
			if (little[i + 1] == '\0')
				return ((char*)&big[a]);
			i++;
		}
		a++;
		len--;
	}
	return (NULL);
}
