/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:08:39 by dlyubich          #+#    #+#             */
/*   Updated: 2018/05/18 14:09:41 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void    parse_map_size(char *buf, t_fill *filler)
{
    if (!ft_strncmp(buf, "Plateau", 7))
    {
        buf = ft_strchr(buf, ' ') + 1;
        filler->map_height = ft_atoi(buf);
        filler->map_width = ft_atoi(ft_strchr(buf, ' '));
    }
	else
		ft_error();
}

void    parse_player(char *buf, t_fill *filler)
{
    if (ft_strlen(buf) > 10 && (buf[10] == '1' || buf[10] == '2'))
    {
        if (buf[10] == '1')
        {
            filler->sym = 'O';
            filler->enemy = 'X';
        }
        else
        {
            filler->sym = 'X';
            filler->enemy = 'O';
        }
    }
    else
		ft_error();
}

void	parse_token(char *buf, t_fill *filler)
{
	if (!ft_strncmp(buf, "Piece", 5))
	{
		buf = ft_strchr(buf, ' ') + 1;
		filler->token_height = ft_atoi(buf);
		filler->token_width = ft_atoi(ft_strchr(buf, ' '));
	}
	else
		ft_error();
}
