/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:48:33 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:48:34 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "libft.h"

t_gnls	*g_gnl;

// static int8_t	gnl_fd(int fd)
// {

// 	if (fd >= 0 && !read(fd, 0, 0))
// 		return (1);
// 	gnl = &g_head;
// 	while (*gnl)
// 	{
// 		if ((*gnl)->fd == fd)
// 		{
// 			tmp = *gnl;
// 			*gnl = (*gnl)->next;
// 			free(tmp);
// 			break ;
// 		}
// 		gnl = &(*gnl)->next;
// 	}
// 	return (0);
// }

static t_gnl	*get_gnl(int fd)
{
	size_t	i;
	t_gnl	*gnl;

	if (!g_gnl && !(g_gnl = ft_array(1)))
		return (0);
	i = -1;
	while (++i < g_gnl->len)
		if (g_gnl->gnl[i]->fd == fd)
			return (g_gnl->gnl[i]);
	if (!(gnl = ft_memalloc(sizeof(t_gnl))))
		return (0);
	gnl->fd = fd;
	return (ft_array_push(g_gnl, gnl));
}

static int8_t	gnl_join(char **line, int *len, t_gnl *gnl)
{
	ssize_t	i;

	i = gnl->i;
	while (gnl->i < gnl->size && gnl->buff[gnl->i] != '\n')
		gnl->i++;
	*line = ft_memcpy(ft_mlc(*len + gnl->i - i + 1), *line, *len);
	ft_memcpy(*line + *len, gnl->buff + i, gnl->i - i);
	*len += gnl->i - i + 1;
	*line[*len] = '\0';
	return (gnl->i < gnl->size);
}

ssize_t			ft_gnl(int fd, char **line)
{
	t_gnl	*gnl;

	if (fd < 0 || !line || !(gnl = get_gnl(fd)))
		return (ERROR(-2));
	*line = 0;
	fd = 0;
	if (gnl->i < gnl->size)
	{
		gnl->i++;
		gnl_join(line, &fd, gnl);
	}
	if (gnl->i >= gnl->size)
		while ((gnl->size = read(gnl->fd, gnl->buff, BUFF_SIZE)) > 0)
		{
			gnl->i = 0;
			if (gnl_join(line, &fd, gnl))
				return ((ssize_t)fd);
		}
	exit(0);
	if (gnl->size == -1)
		return (ERROR(-2));
	if (*line)
		return ((ssize_t)fd);
	return (ERROR(-1));
}
