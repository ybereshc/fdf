/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:42:47 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:42:49 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_separator(char *str)
{
	static int8_t	i;

	if (i)
		W(str);
	else
		i = 1;
}
