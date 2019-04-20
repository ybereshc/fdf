/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:48:33 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:48:34 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include <unistd.h>
# define BUFF_SIZE 256
# define ERROR(e) ((ssize_t)(*line = 0) + e)

typedef struct s_gnl	t_gnl;
typedef struct s_gnls	t_gnls;

struct	s_gnls
{
	t_gnl	**gnl;
	size_t	len;
	size_t	max;
};

struct	s_gnl
{
	int		fd;
	ssize_t	i;
	ssize_t	size;
	char	buff[BUFF_SIZE];
};

#endif
