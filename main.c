/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:34:44 by ybereshc          #+#    #+#             */
/*   Updated: 2019/03/10 20:34:45 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

char	g_buff[256];
size_t	g_i;
size_t	g_size;

static void	len_find_ln(char *buff)
{
	while (buff[g_i] && buff[g_i] != '\n')
		g_i++;
	buff[g_i] = 0;
}

char		*lem_gnl(int fd)
{
	size_t	n;
	char	*res;

	if (read(fd, 0, 0))
	{

	}
	res = 0;
	if (++g_i < g_size)
	{
		n = g_i;
		len_find_ln(g_buff);
		res = ft_strjoin(res, g_buff + n);
	}
	if (g_i >= g_size)
		while ((g_size = read(fd, g_buff, 255)))
		{
			g_i = 0;
			g_buff[g_size] = 0;
			len_find_ln(g_buff);
			res = ft_strfjoin(res, g_buff, 1);
			if (g_i < g_size)
				break ;
		}
	return (res);
}

void	create_map(void)
{
	int	i;

	g_map = ft_mlc(SIZE(int*, 10));
	i = -1;
	while (++i < 10)
	{
		g_map[i] = ft_mlc(SIZE(int, 15));
	}
}

void	read_map(char *file_path)
{
	int	fd;

	if ((fd = open(file_path, O_RDONLY)) < 0)
	{
		D(2, "Invalid file path!\n");
		exit(0);
	}

}

void	writ(t_hashtbl *ary)
{
	size_t i;

	i = -1;
	while (++i < ary->len)
	{
		ft_printf("%U) %s => %s\n", i, ary->key[i], ary->ptr[i]);
	}
}

int	main(int argc, char **argv)
{
	FT_INIT(MLC_ERROR | MLC_EXIT);
	if (argc != 2)
		D(2, "Usage\n");
	// read_map(argv[1]);
	t_hashtbl *ary = ft_hashtbl(1);
	// ft_hashtbl_push(ary, "0a", "zxc");
	// ft_hashtbl_push(ary, "1a", "zxc");
	// ft_hashtbl_push(ary, "2a", "zxc");
	// ft_hashtbl_push(ary, "3a", "zxc");
	// ft_hashtbl_push(ary, "4a", "zxc");
	// ft_hashtbl_push(ary, "5a", "zxc");
	// ft_hashtbl_push(ary, "6a", "agafawdawfwfawdaw");
	// ft_hashtbl_push(ary, "7a", "zxc");
	// ft_hashtbl_push(ary, "8a", "zxc");
	// ft_hashtbl_push(ary, "9a", "zxc");
	// ft_hashtbl_push(ary, "10a", "zxc");
	// ft_hashtbl_push(ary, "11a", "zxc");
	writ(ary);
	// printf("%s\n", ft_hashtbl_get(ary, "0aa"));
	return (0);
}













