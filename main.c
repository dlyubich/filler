/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:57:15 by dlyubich          #+#    #+#             */
/*   Updated: 2018/05/12 11:58:48 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_fill	*filler;

	filler = (t_fill*)malloc(sizeof(t_fill));
	init_struct(filler);
	parse_player(check_gnl(), filler);
	if (parse_map_size(check_gnl(), filler))
		ft_error();
	while (1)
	{
		filler->x = 0;
		filler->y = 0;
		(void)check_gnl();
		parse_loop(&filler->board, filler->map_height, 1);
		if (parse_token(check_gnl(), filler))
			ft_error();
		parse_loop(&filler->token, filler->token_height, 0);
		ft_main_solution(filler);
		(void)check_gnl();
	}
}
