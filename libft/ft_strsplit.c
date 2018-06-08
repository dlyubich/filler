/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:49:13 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/04 19:49:14 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countw(char	const *s, char c)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	if (!k)
		k++;
	return (k);
}

static char	**ft_oper(char const *s, char c, char **str, int j)
{
	int		start;
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i] && ++flag)
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		str[j++] = ft_strsub(s, start, i - start);
	}
	if (!j && !flag && s[0])
		str[j++] = ft_strnew(0);
	str[j] = NULL;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_countw(s, c) + 1))))
		return (NULL);
	return (ft_oper(s, c, str, 0));
}
