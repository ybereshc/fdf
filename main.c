/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:47:58 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/25 21:44:45 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

void		destructor(void)
{
	if (g_win.ptr && g_win.win)
		mlx_destroy_window(g_win.ptr, g_win.win);
	// W("\e[91m");system("leaks -q fdf");W("\e[0m");
}

char		*read_file(char *file_path)
{
	int		fd;
	char	*res;
	char	buff[1024];
	ssize_t	size;

	if (!file_path || (fd = open(file_path, 0)) < 0)
		return (0);
	res = 0;
	while ((size = read(fd, buff, 1023)) > 0)
	{
		buff[size] = '\0';
		res = ft_strfjoin(res, buff, 1);
	}
	return (res);
}

t_color		*create_color(char *str)
{
	t_color	*res;
	uint	color;

	if (!str || ft_strncmp(str, "0x", 2) || ft_strlen(str + 2) != 6)
		color = 0xffffff;
	else
		color = ft_str_to_uint(str + 2, 16);
	res = ft_mlc(sizeof(t_color));
	res->r = color >> 16;
	res->g = color >> 8;
	res->b = color;
	return (res);
}

t_vertex	*create_vertex(int x, int y, char *str)
{
	t_vertex	*res;
	t_split		*vertex;

	if (!(vertex = ft_strsplitany(str, ",")))
		exit(0);
	res = ft_mlc(sizeof(t_vertex));
	res->x = g_map.m * x;
	res->y = g_map.m * y;
	res->z = ft_atoi(vertex->word[0]);
	res->color = create_color(vertex->len > 1 ? vertex->word[1] : 0);
	ft_free_strsplit(vertex);
	return (res);
}

void		parse(char *data)
{
	t_split	*row;
	t_split	*col;
	size_t	y;
	size_t	x;

	if (!(row = ft_strsplitany(data, "\n")) || !row->len)
		exit(0);
	g_map.y = row->len;
	g_map.vtx = ft_array(1);
	y = -1;
	while (++y < row->len)
	{
		if (!(col = ft_strsplitany(row->word[y], "\t ")) && g_map.x && g_map.x != col->len)
			exit(0);
		g_map.x = col->len;
		x = -1;
		while (++x < col->len)
			ft_array_push(g_map.vtx, create_vertex(x, y, col->word[x]));
		ft_free_strsplit(col);
	}
	ft_free_strsplit(row);
}

int			hook(int key)
{
	W("key: [%zu]\n", key);
	if (key == 53)
		exit(0);
	return (0);
}


// extern int __argc;
// extern char ** __argv;
// extern wchar_t ** __wargv

int			main(int argc, char **argv)
{
	char	*data;

	FT_INIT(MLC_ERROR | MLC_EXIT);
	if (argc != 2)
		D(2, "Usage\n");
	data = read_file(argv[1]);
	parse(data);
	free(data);

	g_win.w = g_win.w ? g_win.w : WIN_WIDTH;
	g_win.h = g_win.h ? g_win.h : WIN_HEIGHT;
	g_win.m = g_win.m ? g_win.m : WIN_MARGIN;
	g_map.m = MIN((g_win.w - g_win.m) / g_map.x, (g_win.h - g_win.m) / g_map.y);

	// g_mlx.ptr = mlx_init();
	// g_mlx.win = mlx_new_window(g_mlx.ptr, WIDTH, HEIGHT, "FdF");
	// mlx_hook(g_mlx.win, 2, 5, hook, data);
	// mlx_hook(g_mlx.win, 17, 1L << 17, exit, 0);
	// render();
	// mlx_loop(g_mlx.ptr);
	return (0);
}
