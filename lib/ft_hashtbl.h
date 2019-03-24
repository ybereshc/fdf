/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtbl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:42:29 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:42:31 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHTBL_H
# define FT_HASHTBL_H

# include "libft.h"

typedef struct	s_hashtbl
{
	char	**key;
	void	**ptr;
	size_t	len;
	size_t	max;
}				t_hashtbl;

#endif
