/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:34:44 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/25 21:42:19 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "fdf.h"
#define roundf(x) floor(x + 0.5f)

void	put_pixel(int x, int y, int color)
{
	// uint int_color = color.r << 16 | color.g << 8 | color.b;

	mlx_pixel_put(g_win.ptr, g_win.win, x, y, 0xffffff);
}

void	put_line(int x1, int y1, int x2, int y2)
{
	int dx = (x2 - x1 >= 0 ? 1 : -1);
	int dy = (y2 - y1 >= 0 ? 1 : -1);
	int lengthX = abs(x2 - x1);
	int lengthY = abs(y2 - y1);
	int length = lengthX > lengthY ? lengthX : lengthY;

	int x = x1;
	int y = y1;
	int d = -lengthX;

	if (length == 0)
		put_pixel(x, y, 0);
	else if (lengthY <= lengthX)
	{
		length++;
		while(length--)
		{
			put_pixel(x, y, 0);
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

		length++;
		while(length--)
		{
			put_pixel(x, y, 0);
			y += dy;
			d += 2 * lengthX;
			if (d > 0) {
				d -= 2 * lengthY;
				x += dx;
			}
		}
	}
}

void	render()
{
	size_t		i;
	t_vertex	*vtx;

	i = -1;
	while (++i < g_map.vtx->len)
	{
		vtx = g_map.vtx->vtx[i];
		// print_vertex(vtx);
		// printf("\n");
		// printf("1231231\n");
		put_pixel(vtx->x, vtx->y, 0);
		// put_line(vtx->y, vtx->x, (y + 1) * 10, (x + 1) * 10);
		// mlx_pixel_put(g_mlx.ptr, g_mlx.win, x * g_fdf.space, y * g_fdf.space, 0xffffff);
	}
}
