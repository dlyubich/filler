/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:59:14 by dlyubich          #+#    #+#             */
/*   Updated: 2018/05/12 12:09:12 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>

typedef struct	s_fill
{
	int			x;
	int			y;
	int			**map;
	char		sym;
	char		enemy;
	char		**token;
	char		**board;
	int			map_width;
	int			map_height;
	int			token_width;
	int			token_height;
}				t_fill;

void			ft_error(void);
void			init_struct(t_fill *filler);
int				parse_map_size(char *buf, t_fill *filler);
void			parse_player(char *buf, t_fill *filler);
int				parse_token(char *buf, t_fill *filler);
int				check_minus_one(t_fill *filler);
void			solution(t_fill *filler, int i, int j);
void			ft_main_solution(t_fill *filler);
void			parse_loop(char ***ret, int n, int fl);
char			*check_gnl(void);
void			ft_printfield(char **field, int player, int width, int height);
int				ft_super_char(char *str, int k, char ch, int player);

#endif
