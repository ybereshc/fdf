/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:56:57 by ybereshc          #+#    #+#             */
/*   Updated: 2019/01/26 18:56:58 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/libft.h"
# include "options.h"

typedef struct s_fdf	t_fdf;
typedef struct s_mlx	t_mlx;
typedef struct s_color	t_color;
typedef struct s_vertex	t_vertex;

struct	s_color
{
	int8_t	r;
	int8_t	g;
	int8_t	b;
};

struct	s_vertex
{
	t_color	color;
	double	x;
	double	y;
	double	z;
};

struct s_point
{
	double	x;
	double	y;
	double	z;
};

struct	s_fdf
{
	t_vertex	**map;
	int			x;
	int			y;
	int			space;
};

struct	s_mlx
{
	void	*ptr;
	void	*win;
};

t_fdf	g_fdf;
t_mlx	g_mlx;

void	destructor(void) __attribute__((destructor(101)));

#endif
