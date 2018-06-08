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

void    init_struct(t_fill *filler)
{
    filler->map_height = 0;
    filler->map_width = 0;
    filler->token_height = 0;
    filler->token_width = 0;
    filler->token = NULL;
    filler->x = 0;
    filler->y = 0;
    filler->map = NULL;
    filler->board = NULL;
}

char	*check_gnl()
{
	char *buf;

	if (get_next_line(0, &buf) > 0)
		return (buf);
	else
		exit(EXIT_SUCCESS);
}

void	parse_loop(char ***ret, int n, int fl)
{
	int	i;
	char **mas;

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

int		main(void)
{
    t_fill *filler;

    filler = (t_fill*)malloc(sizeof(t_fill));
    init_struct(filler);
    parse_player(check_gnl(), filler);
    parse_map_size(check_gnl(), filler);
    while (1)
    {
		(void)check_gnl();
		parse_loop(&filler->board, filler->map_height, 1);
		parse_token(check_gnl(), filler);
		parse_loop(&filler->token, filler->token_height, 0);
		ft_main_solution(filler);
		(void)check_gnl();
    }
}
