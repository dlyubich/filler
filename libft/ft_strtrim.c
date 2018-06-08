/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:32:16 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/02 13:32:17 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	i = 0;
	k = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!s[i])
		return (ft_strnew(0));
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	str = (char*)malloc(((j - i) + 2) * sizeof(char));
	if (!str)
		return (str);
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
