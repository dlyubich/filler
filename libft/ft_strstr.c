/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:13:45 by dlyubich          #+#    #+#             */
/*   Updated: 2017/10/31 17:13:46 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int a;

	a = 0;
	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[a])
	{
		i = 0;
		while (little[i] == big[a + i])
		{
			if (little[i + 1] == '\0')
				return ((char*)&big[a]);
			i++;
		}
		a++;
	}
	return (NULL);
}
