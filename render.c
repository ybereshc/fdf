/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:34:44 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/26 19:49:20 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "fdf.h"
#define roundf(x) floor(x + 0.5f)

void	put_pixel(t_fdf *fdf, int x, int y, uint color)
{
	mlx_pixel_put(fdf->ptr, fdf->win, x, y, color);
}

void	put_line(t_fdf *fdf, t_vertex *vtx1, t_vertex *vtx2, uint8_t clear)
{
	double dx = (vtx2->x - vtx1->x >= 0 ? 1 : -1);
	double dy = (vtx2->y - vtx1->y >= 0 ? 1 : -1);
	double lengthX = fabs(vtx2->x - vtx1->x);
	double lengthY = fabs(vtx2->y - vtx1->y);
	double length = lengthX > lengthY ? lengthX : lengthY;

	double x = vtx1->x;
	double y = vtx1->y;
	double d = -lengthX;

	if (length++ == 0)
		put_pixel(fdf, x, y, clear ? 0 : vtx1->color);
	else if (lengthY <= lengthX)
	{
		while(length--)
		{
			put_pixel(fdf, x, y, clear ? 0 : vtx1->color);
			x += dx;
			d += 2 * lengthY;
			if (d > 0) {
				d -= 2 * lengthX;
				y += dy;
			}
		}
	}
	else
	{
		d = - lengthY;

		while(length--)
		{
			put_pixel(fdf, x, y, clear ? 0 : vtx1->color);
			y += dy;
			d += 2 * lengthX;
			if (d > 0) {
				d -= 2 * lengthY;
				x += dx;
			}
		}
	}
}

void	clean(t_fdf *fdf)
{
	size_t		y;
	size_t		x;
	t_vertex	*vtx1;
	t_vertex	*vtx2;

	y = -1;
	while (++y < fdf->y)
	{
		x = -1;
		while (++x < fdf->x)
		{
			if (x < fdf->x - 1)
				put_line(fdf, &fdf->vtx[y][x], &fdf->vtx[y][x + 1], 1);
			if (y < fdf->y - 1)
				put_line(fdf, &fdf->vtx[y][x], &fdf->vtx[y + 1][x], 1);
		}
	}
}

void	render(t_fdf *fdf)
{
	size_t		y;
	size_t		x;

	y = -1;
	while (++y < fdf->y)
	{
		x = -1;
		while (++x < fdf->x)
		{
			if (x < fdf->x - 1)
				put_line(fdf, &fdf->vtx[y][x], &fdf->vtx[y][x + 1], 0);
			if (y < fdf->y - 1)
				put_line(fdf, &fdf->vtx[y][x], &fdf->vtx[y + 1][x], 0);
		}
	}
}
