#include "filler.h"

int		check_minus_one(t_fill *filler)
{
	int	i;
	int	j;

	i = 0;
	while (i < filler->map_height)
	{
		j = 0;
		while (j < filler->map_width)
		{
			if (filler->map[i][j] == -1)
                return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int     count_distance(t_fill *filler, int i, int j)
{
    int a;
    int b;
    int sum;

    a = -1;
    sum = 0;
    while (++a < filler->token_height)
    {
        b = -1;
        while (++b < filler->token_width)
        {
            if (filler->token[a][b] == '*')
                sum += filler->map[i + a][j + b];
        }
    }
    return (sum);
}

int     try_to_place(t_fill *filler, int i, int j)
{
    int a;
    int b;
    int c;

    a = -1;
    c = 0;
    while (++a < filler->token_height)
    {
        b = -1;
        while (++b < filler->token_width)
        {
            if ((i + a >= filler->map_height) || b + j >= filler->map_width)
                return (0);
            else if (filler->board[i + a][b + j] == filler->enemy || filler->board[i + a][b + j] == filler->enemy + 32)
                return (0);
            else if (filler->board[i + a][b + j] == filler->sym)
                c++;
        }
    }
    return (c == 1 ? 1 : 0);
}

void    solution(t_fill *filler, int i, int j)
{
    int res;
    int tmp;

    res = 2147483647;
    tmp = 0;
    while (++i < filler->map_height)
    {
        j = -1;
        while (++j < filler->map_width)
        {
            if (try_to_place(filler, i, j))
            {
                if ((tmp = count_distance(filler, i, j)) < res)
                {
                    res = tmp;
                    filler->x = j;
                    filler->y = i;
                }
            }
        }
    }
}
