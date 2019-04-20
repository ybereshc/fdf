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

int	main(int argc, char **argv)
{
	FT_INIT(MLC_ERROR | MLC_EXIT);
	if (argc != 2)
		D(2, "Usage\n");

	int fd = open("42.fdf", 0);
	char *line;
	while (ft_gnl(fd, &line) >= 0)
	{
		free(line);
		// W("%s\n", line);
	}
	return (0);
}

