/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:54:01 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/25 18:44:21 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "fdf.h"

void	print_color(t_color *color)
{
	printf("Color (red: %u, green: %u, blue: %u)", color->r, color->g, color->b);
}

void	print_vertex(t_vertex *vertex)
{
	printf("Vertex (x: %.2f, y: %.2f, z: %.2f)", vertex->x, vertex->y, vertex->z);
}