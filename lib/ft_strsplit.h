/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:42:29 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:42:31 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRSPLIT_H
# define FT_STRSPLIT_H

# include "libft.h"

typedef struct s_split	t_split;

struct	s_split
{
	char	**word;
	size_t	len;
};

#endif
