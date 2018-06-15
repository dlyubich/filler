/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_visual.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:50:32 by dlyubich          #+#    #+#             */
/*   Updated: 2018/06/14 15:50:38 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_read_write(void)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		(void)check_gnl();
		i++;
	}
}

int			ft_checkplayer(void)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
		ft_error();
	if (line[6] == 'O')
	{
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	return (2);
}

int			main(void)
{
	t_fill	*filler;
	int		tmp;

	filler = (t_fill*)malloc(sizeof(t_fill));
	init_struct(filler);
	tmp = 0;
	ft_read_write();
	while (1)
	{
		if (!parse_map_size(check_gnl(), filler) && check_gnl())
		{
			parse_loop(&filler->board, filler->map_height, 1);
			usleep(166666);
			system("clear");
			ft_printfield(filler->board, 0, filler->map_width,
			filler->map_height);
		}
		if (!parse_token(check_gnl(), filler))
		{
			parse_loop(&filler->token, filler->token_height, 0);
			ft_printfield(filler->token, ft_checkplayer(),
			filler->token_width, filler->token_height);
		}
	}
	return (0);
}
