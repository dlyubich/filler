/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:57:55 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/08 16:57:55 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strreverse(const char *s)
{
	char	*new;
	int		start;
	int		i;

	i = 0;
	start = ft_strlen(s);
	new = (char*)malloc((start + 1) * sizeof(char));
	while (start--)
		new[i++] = s[start];
	new[i] = '\0';
	return (new);
}
