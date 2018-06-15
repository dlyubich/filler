/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:49:55 by dlyubich          #+#    #+#             */
/*   Updated: 2018/06/14 15:50:01 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_printfield(char **field, int player, int width, int height)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!(str = ft_strnew(height * width * 5 + 1)))
		ft_error();
	k = 0;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			k += ft_super_char(str, k, field[i][j], player);
			str[k++] = ' ';
		}
		str[k++] = '\n';
	}
	str[k++] = '\0';
	ft_printf("%s\n", str);
}

int		ft_super_char(char *str, int k, char ch, int player)
{
	if (ch == 'o' || ch == 'O' || (ch == '*' && player == 1))
	{
		str[k++] = (char)240;
		str[k++] = (char)159;
		str[k++] = (char)146;
		str[k] = (char)147;
		return (4);
	}
	if (ch == 'x' || ch == 'X' || ch == '*')
	{
		str[k++] = (char)240;
		str[k++] = (char)159;
		str[k++] = (char)166;
		str[k] = (char)139;
		return (4);
	}
	if (ch == '.')
	{
		str[k++] = (char)226;
		str[k++] = (char)154;
		str[k] = (char)171;
	}
	return (3);
}
