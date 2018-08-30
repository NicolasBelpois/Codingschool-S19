/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:36:42 by nbelpois          #+#    #+#             */
/*   Updated: 2018/08/30 14:11:03 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int				put_tetri_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_tetri		*tetri;

	if (list == NULL)
		return (1);
	y = 0;
	tetri = (list->content);
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (place_tetri(tetri, map, x, y))
			{
				if (put_tetri_map(map, list->next))
					return (1);
				else
					lock_tetri(tetri, map, new_position(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int				place_tetri(t_tetri *tetri, t_map *map, int x, int y)
{
	int			i;
	int			j;

	i = 0;
	while (i < tetri->w)
	{
		j = 0;
		while (j < tetri->h)
		{
			if (tetri->pos[i][j] == '#' && map->tab[y + i][x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	lock_tetri(tetri, map, new_position(x, y), tetri->letter);
	return (1);
}

void			lock_tetri(t_tetri *tetri, t_map *map, t_pos *position, char c)
{
	int			i;
	int			j;

	i = 0;
	while (i < tetri->w)
	{
		j = 0;
		while (j < tetri->h)
		{
			if (tetri->pos[i][j] == '#')
				map->tab[position->y + i][position->x + j] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&position);
}

int				map_size(int nb_tetri)
{
	int			size;

	size = 2;
	while (size * size < nb_tetri)
		size++;
	return (size);
}

t_map			*solve(t_list *list)
{
	t_map		*map;
	int			size;

	size = map_size(ft_lstcount(list) * 4);
	map = map_create(size);
	while (!put_tetri_map(map, list))
	{
		size++;
		map_free(map);
		map = map_create(size);
	}
	return (map);
}
