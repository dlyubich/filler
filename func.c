/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:25:48 by dlyubich          #+#    #+#             */
/*   Updated: 2018/06/14 14:25:49 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		init_struct(t_fill *filler)
{
	filler->map_height = 0;
	filler->map_width = 0;
	filler->token_height = 0;
	filler->token_width = 0;
	filler->token = NULL;
	filler->map = NULL;
	filler->board = NULL;
}

char		*check_gnl(void)
{
	char	*buf;

	if (get_next_line(0, &buf) > 0)
		return (buf);
	else
		exit(EXIT_SUCCESS);
}

void		parse_loop(char ***ret, int n, int fl)
{
	int		i;
	char	**mas;

	i = 0;
	mas = (char**)malloc(sizeof(char*) * (n + 1));
	while (i < n)
	{
		mas[i] = fl ? check_gnl() + 4 : check_gnl();
		i++;
	}
	mas[i] = NULL;
	*ret = mas;
}
