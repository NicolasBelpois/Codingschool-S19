/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:19:46 by nbelpois          #+#    #+#             */
/*   Updated: 2018/08/30 14:27:21 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"
#include "libft.h"

void		minmax_value(char *str, t_pos *min, t_pos *max)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

int			is_tetri(char *str)
{
	int		i;
	int		connect;

	connect = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				connect++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				connect++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				connect++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				connect++;
		}
		i++;
	}
	return (connect == 6 || connect == 8);
}

int			is_error(char *str, int ret)
{
	int		i;
	int		bloc;

	i = 0;
	bloc = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++bloc > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (ret == 21 && str[20] != '\n')
		return (4);
	if (!is_tetri(str))
		return (5);
	return (0);
}

t_list		*read_fd(int fd)
{
	char	*buf;
	int		ret;
	t_list	*list;
	t_tetri	*tetri;
	char	letter;

	buf = ft_strnew(21);
	list = NULL;
	letter = 'A';
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		if (is_error(buf, ret) != 0 ||
				(tetri = get_tetri(buf, letter++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetri, sizeof(t_tetri)));
		ft_memdel((void **)&tetri);
	}
	ft_memdel((void **)&buf);
	if (ret != 0)
		return (free_list(list));
	return (list);
}

t_tetri		*get_tetri(char *str, char letter)
{
	t_pos	*mi;
	t_pos	*ma;
	char	**pos;
	int		i;
	t_tetri	*tetri;

	mi = new_position(3, 3);
	ma = new_position(0, 0);
	minmax_value(str, mi, ma);
	pos = ft_memalloc(sizeof(char *) * (ma->y - mi->y + 1));
	i = 0;
	while (i < ma->y - mi->y + 1)
	{
		pos[i] = ft_strnew(ma->x - mi->x + 1);
		ft_strncpy(pos[i], str + (mi->x) + (i + mi->y) * 5, ma->x - mi->x + 1);
		i++;
	}
	tetri = create_tetri(pos, ma->x - mi->x + 1, ma->y - mi->y + 1, letter);
	ft_memdel((void **)&mi);
	ft_memdel((void **)&ma);
	return (tetri);
}
