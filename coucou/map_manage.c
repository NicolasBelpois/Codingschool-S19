/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:51:09 by nbelpois          #+#    #+#             */
/*   Updated: 2018/08/30 14:13:23 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*map_create(int size)
{
	t_map	*map;
	int		i;
	int		j;

	if (!(map = ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->tab = ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		map->tab[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void		map_free(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->tab[i]));
		i++;
	}
	ft_memdel((void **)&(map->tab));
	ft_memdel((void **)&map);
}

void		map_draw(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->tab[i]);
		ft_putchar('\n');
		i++;
	}
}
