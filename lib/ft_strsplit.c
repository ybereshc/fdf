/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:25:10 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/26 12:25:11 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strsplit.h"

static char	*split_pass(char *str1, char *str2)
{
	while (ft_strchr(str2, *str1))
		str1++;
	return (str1);
}

t_split		*ft_strsplitany(char *str1, char *str2)
{
	t_split	*res;
	char	*beg;

	res = ft_array(10);
	while (*(str1 = split_pass(str1, str2)))
	{
		beg = str1;
		while (*str1 && !ft_strchr(str2, *str1))
			str1++;
		ft_array_push(res, ft_strndup(beg, str1 - beg));
	}
	return (ft_array_split(res, 0));
}

t_split		*ft_strfsplitany(char *str1, char *str2)
{
	t_split	*res;
	char	*beg;

	res = ft_array(1);
	while (*(str1 = split_pass(str1, str2)))
	{
		beg = str1;
		while (*str1 && !ft_strchr(str2, *str1))
			str1++;
		ft_array_push(res, beg);
		if (*str1)
			*str1++ = '\0';
	}
	return (ft_array_split(res, 0));
}

void	*ft_free_strsplit(t_split *split)
{
	size_t	i;

	i = -1;
	while (++i < split->len)
		free(split->word[i]);
	return (ft_array_free(split));
}
