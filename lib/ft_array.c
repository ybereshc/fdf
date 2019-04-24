/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:42:47 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:42:49 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"

void	*ft_array(size_t count)
{
	t_array	*res;

	if (!count || !(res = ft_mlc(sizeof(t_array))))
		return (0);
	if (!(res->ptr = ft_mlc(SIZE(void*, count))))
	{
		free(res);
		return (0);
	}
	res->len = 0;
	res->max = count;
	return (res);
}

void	*ft_array_push(void *array, void *ptr)
{
	t_array	*ary;

	if (!array)
		return (0);
	ary = array;
	if (ary->len >= ary->max && !(ft_array_split(ary, ary->max * 3)))
		return (0);
	return (ary->ptr[ary->len++] = ptr);
}

void	*ft_array_split(void *array, size_t count)
{
	t_array	*ary;
	void	*tmp;

	if (!array)
		return (0);
	ary = array;
	if (!ary->len)
		return (ft_array_free(ary));
	if (count == ary->len)
		return (array);
	if (!count)
		count = ary->len;
	if (!(tmp = ft_mlc(SIZE(void*, count))))
		return (0);
	ft_memcpy(tmp, ary->ptr, SIZE(void*, count));
	free(ary->ptr);
	ary->ptr = tmp;
	ary->max = count;
	return (array);
}

void	*ft_array_free(void *array)
{
	if (array)
		free(((t_array*)array)->ptr);
	free(array);
	return (0);
}
