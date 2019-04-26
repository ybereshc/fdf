/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:54:01 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/26 17:33:34 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "fdf.h"

void	print_color(uint color)
{
	printf("Color (red: %u, green: %u, blue: %u)", color >> 16 & 0xff, color >> 8 & 0xff, color & 0xff);
}

void	print_vertex(t_vertex *vertex)
{
	printf("Vertex (x: %.2f, y: %.2f, z: %.2f)", vertex->x, vertex->y, vertex->z);
}