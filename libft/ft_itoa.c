/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:18:54 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/02 19:18:56 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_of_digits(int n)
{
	int num;

	num = 0;
	if (n == 0)
		num++;
	if (n < 0)
	{
		n *= -1;
		num++;
	}
	while (n > 0)
	{
		n /= 10;
		num++;
	}
	return (num + 1);
}

static void	is_negative(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		num;
	int		fl;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = number_of_digits(n);
	fl = 0;
	is_negative(&n, &fl);
	str = (char*)malloc((num) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[--num] = '\0';
	while (--num >= 0)
	{
		str[num] = n % 10 + '0';
		n /= 10;
	}
	if (fl == 1)
		str[0] = '-';
	return (str);
}
