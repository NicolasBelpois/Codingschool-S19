/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 09:46:48 by nbelpois          #+#    #+#             */
/*   Updated: 2018/08/30 14:21:28 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include "libft.h"

typedef	struct	s_map
{
	int			size;
	char		**tab;
}				t_map;

typedef	struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef	struct	s_tetri
{
	char		**pos;
	int			w;
	int			h;
	char		letter;
}				t_tetri;

void			ft_gettetri(char *lst);
void			minmax_value(char *str, t_pos *min, t_pos *max);
void			map_free(t_map *map);
void			map_draw(t_map *map);
void			free_tetri(t_tetri *tetri);
void			lock_tetri(t_tetri *tetri, t_map *map, t_pos *position, char c);

t_list			*read_fd(int fd);
t_list			*free_list(t_list *list);

t_pos			*new_position(int x, int y);

t_tetri			*get_tetri(char *str, char letter);
t_tetri			*create_tetri(char **pos, int w, int h, char letter);

int				is_error(char *str, int ret);
int				map_size(int nb_tet);
int				put_tetri_map(t_map *map, t_list *list);
int				place_tetri(t_tetri *tetri, t_map *map, int x, int y);

t_map			*map_create(int size);
t_map			*solve(t_list *list);
#endif
