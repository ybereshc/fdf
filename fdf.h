/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:56:57 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/26 20:07:29 by ybereshc         ###   ########.fr       */
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
# define WIN_PADDING 100
# define DEFAULT_COLOR 0xffffff

typedef struct s_fdf		t_fdf;
typedef struct s_vertex		t_vertex;

struct	s_vertex
{
	uint	color;
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

struct	s_fdf
{
	void		*ptr;
	void		*win;
	size_t		width;
	size_t		height;
	t_vertex	**vtx;
	size_t		x;
	size_t		y;
};

void	destructor(void) __attribute__((destructor(101)));
char	*read_file(t_fdf *fdf, char *file_path);
void	parse(t_fdf *fdf, char *data);
void	clean(t_fdf *fdf);
void	render(t_fdf *fdf);

#endif
