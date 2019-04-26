/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:47:58 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/26 20:08:35 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

char			*read_file(t_fdf *fdf, char *file_path)
{
	int		fd;
	char	*res;
	char	buff[1024];
	ssize_t	size;

	if (!file_path || (fd = open(file_path, 0)) < 0)
		exit(0);
	res = 0;
	while ((size = read(fd, buff, 1023)) > 0)
	{
		buff[size] = '\0';
		res = ft_strfjoin(res, buff, 1);
	}
	return (res);
}

static uint		create_color(char *str)
{
	uint	color;

	if (!str || ft_strncmp(str, "0x", 2) || ft_strlen(str + 2) != 6)
		return (DEFAULT_COLOR);
	return (ft_str_to_uint(str + 2, 16));
}

static t_vertex	create_vertex(t_fdf *fdf, int x, int y, char *str)
{
	t_vertex	res;
	t_split		*vertex;

	if (!(vertex = ft_strsplitany(str, ",")))
		exit(0);
	res.x = x;
	res.y = y;
	res.z = ft_atoi(vertex->word[0]);
	res.color = create_color(vertex->len > 1 ? vertex->word[1] : 0);
	ft_free_strsplit(vertex);
	return (res);
}

void			parse(t_fdf *fdf, char *data)
{
	t_split	*row;
	t_split	*col;
	size_t	y;
	size_t	x;

	if (!(row = ft_strsplitany(data, "\n")) || !row->len)
		exit(0);
	fdf->y = row->len;
	fdf->vtx = malloc(SIZE(t_vertex*, fdf->y));
	y = -1;
	while (++y < row->len)
	{
		if (!(col = ft_strsplitany(row->word[y], "\t ")))
			exit(0);
		if (!y)
			fdf->x = col->len;
		else if (fdf->x != col->len)
			exit(0);
		fdf->vtx[y] = malloc(SIZE(t_vertex, fdf->x));
		x = -1;
		while (++x < col->len)
			fdf->vtx[y][x] = create_vertex(fdf, x, y, col->word[x]);
		ft_free_strsplit(col);
	}
	ft_free_strsplit(row);
}
