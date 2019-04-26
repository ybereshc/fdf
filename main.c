/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:47:58 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/26 20:25:37 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "fdf.h"

void		destructor(void)
{
	W("\e[91m");system("leaks -q fdf");W("\e[0m");
}

void		fdf_move(t_fdf *fdf, int key)
{
	size_t		y;
	size_t		x;

	y = -1;
	while (++y < fdf->y)
	{
		x = -1;
		while (++x < fdf->x)
		{
			if (key == 126)
				fdf->vtx[y][x].y -= 10;
			if (key == 123)
				fdf->vtx[y][x].x -= 10;
			if (key == 125)
				fdf->vtx[y][x].y += 10;
			if (key == 124)
				fdf->vtx[y][x].x += 10;
		}
	}
}

int			hook(int key, t_fdf *fdf)
{
	W("key: [%zu]\n", key);
	if (key == 53)
	{
		mlx_destroy_window(fdf->ptr, fdf->win);
		exit(0);
	}
	clean(fdf);
	if (key >= 123 && key <= 126)
		fdf_move(fdf, key);
	render(fdf);
	return (0);
}

void		center(t_fdf *fdf)
{
	size_t	y;
	size_t	x;
	double	width;
	double	height;
	double	spase;

	width = (fdf->width - WIN_PADDING * 2 - 1) / (fdf->x - 1);
	height = (fdf->height - WIN_PADDING * 2 - 1) / (fdf->y - 1);
	spase = MIN(width, height);
	height = (fdf->height - (fdf->y - 1) * spase) / 2;
	width = (fdf->width - (fdf->x - 1) * spase) / 2;
	y = -1;
	while (++y < fdf->y)
	{
		x = -1;
		while (++x < fdf->x)
		{
			fdf->vtx[y][x].x = fdf->vtx[y][x].x * spase + width;
			fdf->vtx[y][x].y = fdf->vtx[y][x].y * spase + height;
		}
	}
}

int			main(int argc, char **argv)
{
	char	*data;
	t_fdf	fdf;

	FT_INIT(MLC_ERROR | MLC_EXIT);
	if (argc != 2)
		D(2, "Usage\n");
	ft_bzero(&fdf, sizeof(t_fdf));
	fdf.width = fdf.width ? fdf.width : WIN_WIDTH;
	fdf.height = fdf.height ? fdf.height : WIN_HEIGHT;

	data = read_file(&fdf, argv[1]);
	parse(&fdf, data);
	free(data);

	fdf.ptr = mlx_init();
	fdf.win = mlx_new_window(fdf.ptr, fdf.width, fdf.height, "FdF");
	mlx_hook(fdf.win, 2, 5, hook, &fdf);
	mlx_hook(fdf.win, 17, 1L << 17, (int(*)())exit, &fdf);
	center(&fdf);
	render(&fdf);
	mlx_loop(fdf.ptr);
	return (0);
}
