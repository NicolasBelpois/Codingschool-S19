/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 09:58:13 by nbelpois          #+#    #+#             */
/*   Updated: 2018/08/30 14:13:08 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"
#include "libft.h"

int			main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;

	if (ac != 2)
	{
		write(1, "usage : ./fillit source_file\n		", 29);
		return (1);
	}
	if ((list = read_fd(open(av[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map = solve(list);
	map_draw(map);
	map_free(map);
	free_list(list);
	return (0);
}
