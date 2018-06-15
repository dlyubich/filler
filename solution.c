/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:19:59 by dlyubich          #+#    #+#             */
/*   Updated: 2018/05/18 13:20:09 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**create_mas(int height, int width)
{
	int	i;
	int	j;
	int	**arr;

	i = 0;
	arr = (int**)malloc(sizeof(int*) * (height));
	while (i < height)
	{
		j = 0;
		arr[i] = (int*)malloc(sizeof(int) * width);
		while (j < width)
		{
			arr[i][j] = -1;
			j++;
		}
		i++;
	}
	return (arr);
}

void	fill_mas(t_fill *filler)
{
	int	i;
	int	j;

	i = 0;
	while (i < filler->map_height)
	{
		j = 0;
		while (j < filler->map_width)
		{
			if (filler->board[i][j] == filler->enemy
			|| filler->board[i][j] == filler->enemy + 32)
				filler->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	check_helper(t_fill *filler, int i, int j, int tmp)
{
	if (j - 1 >= 0 && filler->map[j - 1][i] == -1)
		filler->map[j - 1][i] = tmp + 1;
	if (j - 1 >= 0 && i - 1 >= 0 && filler->map[j - 1][i - 1] == -1)
		filler->map[j - 1][i - 1] = tmp + 1;
	if (j - 1 >= 0 && i + 1 < filler->map_width &&
	filler->map[j - 1][i + 1] == -1)
		filler->map[j - 1][i + 1] = tmp + 1;
	if (i - 1 >= 0 && filler->map[j][i - 1] == -1)
		filler->map[j][i - 1] = tmp + 1;
	if (i + 1 < filler->map_width && filler->map[j][i + 1] == -1)
		filler->map[j][i + 1] = tmp + 1;
	if (j + 1 < filler->map_height && filler->map[j + 1][i] == -1)
		filler->map[j + 1][i] = tmp + 1;
	if (j + 1 < filler->map_height && i - 1 >= 0
	&& filler->map[j + 1][i - 1] == -1)
		filler->map[j + 1][i - 1] = tmp + 1;
	if (j + 1 < filler->map_height && i + 1 < filler->map_width
	&& filler->map[j + 1][i + 1] == -1)
		filler->map[j + 1][i + 1] = tmp + 1;
}

void	distance_map(t_fill *filler)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	while (check_minus_one(filler) && tmp != 15)
	{
		j = 0;
		while (j < filler->map_height)
		{
			i = 0;
			while (i < filler->map_width)
			{
				if (filler->map[j][i] == tmp)
					check_helper(filler, i, j, tmp);
				i++;
			}
			j++;
		}
		tmp++;
	}
}

void	ft_main_solution(t_fill *filler)
{
	filler->map = create_mas(filler->map_height, filler->map_width);
	fill_mas(filler);
	distance_map(filler);
	solution(filler, 0 - filler->token_height, -1);
	ft_printf("%d %d\n", filler->y, filler->x);
}
