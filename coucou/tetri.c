/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:28:14 by nbelpois          #+#    #+#             */
/*   Updated: 2018/08/30 14:22:06 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri			*create_tetri(char **pos, int h, int w, char letter)
{
	t_tetri		*tetri;

	tetri = ft_memalloc(sizeof(t_tetri));
	tetri->pos = pos;
	tetri->w = w;
	tetri->h = h;
	tetri->letter = letter;
	return (tetri);
}

void			free_tetri(t_tetri *tetri)
{
	int			y;

	y = 0;
	while (y < tetri->h)
	{
		ft_memdel((void **)&(tetri->pos[y]));
		y++;
	}
	ft_memdel((void **)&(tetri->pos));
	ft_memdel((void **)&tetri);
}

t_pos			*new_position(int x, int y)
{
	t_pos		*position;

	position = ft_memalloc(sizeof(t_pos));
	position->x = x;
	position->y = y;
	return (position);
}

t_list			*free_list(t_list *list)
{
	t_tetri		*tetri;
	t_list		*next;

	while (list)
	{
		tetri = (t_tetri *)list->content;
		next = list->next;
		free_tetri(tetri);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
