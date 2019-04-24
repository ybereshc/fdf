/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:34:44 by ybereshc          #+#    #+#             */
/*   Updated: 2019/03/10 20:34:45 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "fdf.h"
#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>

void	destructor(void)
{
	system("leaks -q fdf");
	// mlx_destroy_window(g_mlx.ptr, g_mlx.win);
}

char	*read_file(char *file_path)
{
	int		fd;
	char	*res;
	char	buff[1025];
	ssize_t	size;

	if (!file_path || (fd = open(file_path, 0)) < 0)
		return (0);
	res = 0;
	while ((size = read(fd, buff, 1024)) > 0)
	{
		buff[size] = '\0';
		res = ft_strfjoin(res, buff, 1);
	}
	return (res);
}

t_color	create_color(char *str)
{
	t_color	res;
	uint	color;

	if (!str || (ft_strncmp(str, "0x", 2) && ft_strncmp(str, "0X", 2)) || ft_strlen(str + 2) != 6)
		color = ft_str_to_uint(str + 2, 16);
	else
		color = 0xffffff;
	res.r = color >> 16;
	res.g = color >> 8;
	res.b = color;
	return (res);
}

t_vertex	create_vertex(int x, int y, char *str)
{
	t_vertex	res;
	t_split		*vertex;

	if (!(vertex = ft_strsplitany(str, ",")))
		exit(0);
	res.x = x;
	res.y = y;
	res.z = ft_atoi(vertex->word[0]);
	if (vertex->len > 1)
	{
		res.color = create_color(vertex->word[1]);
	}
	printf("%f\n", res.z);
	ft_free_strsplit(vertex);
	return (res);
}

void	parse(char *data)
{
	t_split	*row;
	t_split	*col;
	size_t	y;
	size_t	x;

	row = ft_strsplitany(data, "\n");
	if (!row || !(g_fdf.y = row->len))
		exit(0);
	col = ft_strsplitany(row->word[0], "\t ");
	if (!col || !(g_fdf.x = col->len))
		exit(0);
	g_fdf.map = ft_memalloc(SIZE(t_vertex*, g_fdf.y));
	y = -1;
	while (++y < g_fdf.y)
	{
		if (y && (!(col = ft_strsplitany(row->word[y], "\t ")) || col->len != g_fdf.x))
			exit(0);
		g_fdf.map[y] = ft_memalloc(SIZE(t_vertex, g_fdf.x));
		x = -1;
		while (++x < g_fdf.x)
			g_fdf.map[y][x] = create_vertex(x, y, col->word[x]);
		ft_free_strsplit(col);
	}
	ft_free_strsplit(row);
}

int		hook(int key)
{
	W("key: [%zu]\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	char	*data;

	FT_INIT(MLC_ERROR | MLC_EXIT);
	if (argc != 2)
		D(2, "Usage\n");
	data = read_file(argv[1]);
	parse(data);
	free(data);
	g_fdf.space = 100;
	// printf("%f\n", g_fdf.map[1][1].z);

	// g_mlx.ptr = mlx_init();
	// g_mlx.win = mlx_new_window(g_mlx.ptr, g_fdf.x * g_fdf.space, g_fdf.y * g_fdf.space, "XUI");
	// mlx_hook(g_mlx.win, 2, 5, hook, data);
	// mlx_hook(g_mlx.win, 17, 1L << 17, exit, 0);
	// render();
	// mlx_loop(g_mlx.ptr);
	return (0);
}
