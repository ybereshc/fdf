/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:56:57 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/25 21:36:39 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/libft.h"
# include "options.h"
# include <mlx.h>
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define WIN_MARGIN 100

typedef struct s_map		t_map;
typedef struct s_win		t_win;
typedef struct s_color		t_color;
typedef struct s_vertex		t_vertex;
typedef struct s_vector		t_vector;

typedef struct s_vtx_ary	t_vtx_ary;
typedef struct s_vct_ary	t_vct_ary;

struct	s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
};

struct	s_vertex
{
	t_color	*color;
	double	x;
	double	y;
	double	z;
};

struct	s_vector
{
	double	x;
	double	y;
	double	z;
};

struct	s_point
{
	double	x;
	double	y;
	double	z;
};

struct	s_map
{
	t_vtx_ary	*vtx;
	t_vct_ary	*vct;
	size_t		x;
	size_t		y;
	size_t		m;
};

struct	s_win
{
	void	*ptr;
	void	*win;
	size_t	w;
	size_t	h;
	size_t	m;
};

struct	s_vtx_ary
{
	t_vertex	**vtx;
	size_t		len;
};

struct	s_vct_ary
{
	t_vector	**vct;
	size_t		len;
};

t_map		g_map;
t_win		g_win;

void	destructor(void) __attribute__((destructor(101)));

#endif
