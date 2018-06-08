/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:55:38 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/18 17:56:54 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_create(t_list **a, int fd)
{
	t_gnl	new;
	t_list	*list;

	new.fd = fd;
	new.str = ft_strnew(0);
	list = ft_lstnew(&new, sizeof(new));
	ft_lstadd(a, list);
}

int		ft_suball(char **buf, char **line)
{
	int		i;
	char	*tmp;
	char	*str;

	str = *buf;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (0);
	*line = ft_strsub(str, 0, i);
	i++;
	tmp = str;
	str = ft_strdup(str + i);
	*buf = str;
	free(tmp);
	return (1);
}

int		ft_makeread(int fd, char **buf)
{
	char	*red;
	char	*tmp;
	int		i;

	red = ft_strnew(BUFF_SIZE);
	i = read(fd, red, BUFF_SIZE);
	if (i < 0 || !i)
	{
		free(red);
		return (i);
	}
	tmp = *buf;
	*buf = ft_strjoin(*buf, red);
	free(tmp);
	free(red);
	return (1);
}

int		ft_read(int fd, char **buf, char **line)
{
	int		i;
	int		a;

	i = 1;
	while (!(a = ft_suball(buf, line)))
	{
		i = ft_makeread(fd, buf);
		if (i == 0)
		{
			if (*buf[0] != '\0')
			{
				*line = ft_strdup(*buf);
				ft_strdel(buf);
				*buf = ft_strnew(0);
				return (1);
			}
			else
				return (0);
		}
		else if (i < 0)
			return (-1);
	}
	return (a);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*gnl;
	t_list			*lst;
	t_gnl			*lol;

	lst = gnl;
	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	while (lst)
	{
		lol = (t_gnl*)lst->content;
		if (lol->fd == fd)
			break ;
		lst = lst->next;
	}
	if (!lst)
	{
		lst = gnl;
		ft_create(&lst, fd);
		gnl = lst;
	}
	lol = (t_gnl*)lst->content;
	return (ft_read(fd, &lol->str, line));
}
