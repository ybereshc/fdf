/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:42:47 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:42:49 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtbl.h"
#include "libft.h"

void			*ft_hashtbl(size_t count)
{
	t_hashtbl	*res;

	if (!count || !(res = ft_mlc(sizeof(t_hashtbl))))
		return (0);
	res->key = ft_mlc(SIZE(char*, count));
	res->ptr = ft_mlc(SIZE(void*, count));
	if (!res->key || !res->ptr)
	{
		free(res);
		free(res->key);
		free(res->ptr);
		return (0);
	}
	res->len = 0;
	res->max = count;
	return (res);
}

static ssize_t	ft_hashtbl_find(void *ary, char *key)
{
	t_hashtbl	*ary_tmp;
	size_t		l;
	size_t		m;
	size_t		r;
	int8_t		cmp;

	if (!key)
		return (-1);
	ary_tmp = ary;
	l = 0;
	r = ary_tmp->len;
	m = r;
	while (m != (r - l) / 2 + l)
	{
		m = (r - l) / 2 + l;
		cmp = ft_strcmp(ary_tmp->key[m], key);
		if (cmp < 0)
			l = m;
		else if (cmp > 0)
			r = m;
		else
			return (m);
	}
	return (-1);
}

static void		ft_hashtbl_sort(t_hashtbl *ary)
{
	void		*tmp;
	size_t		i;

	if (ary->len < 2)
		return ;
	i = ary->len - 1;
	while (i-- && ft_strcmp(ary->key[i], ary->key[i + 1]) > 0)
	{
		tmp = ary->key[i];
		ary->key[i] = ary->key[i + 1];
		ary->key[i + 1] = (char*)tmp;
		tmp = ary->ptr[i];
		ary->ptr[i] = ary->ptr[i + 1];
		ary->ptr[i + 1] = (char*)tmp;
	}
}

void			*ft_hashtbl_push(void *ary, char *key, void *ptr)
{
	t_hashtbl	*ary_tmp;
	void		*tmp;

	ary_tmp = ary;
	if (!ary_tmp || ft_hashtbl_find(ary, key) < 0)
		return (0);
	if (ary_tmp->len >= ary_tmp->max)
	{
		ary_tmp->max *= 3;
		if (!(tmp = ft_mlc(SIZE(char*, ary_tmp->max))))
			return (0);
		ft_memcpy(tmp, ary_tmp->key, SIZE(char*, ary_tmp->len));
		free(ary_tmp->key);
		ary_tmp->key = (char**)tmp;
		if (!(tmp = ft_mlc(SIZE(void*, ary_tmp->max))))
			return (0);
		ft_memcpy(tmp, ary_tmp->ptr, SIZE(void*, ary_tmp->len));
		free(ary_tmp->ptr);
		ary_tmp->ptr = tmp;
	}
	ary_tmp->key[ary_tmp->len] = key;
	ary_tmp->ptr[ary_tmp->len++] = ptr;
	ft_hashtbl_sort(ary_tmp);
	return (ptr);
}

void			*ft_hashtbl_free(void *ary)
{
	t_hashtbl	*ary_tmp;

	ary_tmp = ary;
	if (ary_tmp && (ary_tmp->key || ary_tmp->ptr))
	{
		free(ary_tmp->key);
		free(ary_tmp->ptr);
	}
	free(ary_tmp);
	return (0);
}
