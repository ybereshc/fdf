/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <ybereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:42:29 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/25 17:59:28 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include "libft.h"

typedef struct s_array	t_array;

struct	s_array
{
	void	**ptr;
	size_t	len;
	size_t	max;
};

#endif
