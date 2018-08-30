/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:04:09 by nbelpois          #+#    #+#             */
/*   Updated: 2018/06/26 11:25:52 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbword(char const *s, char c)
{
	size_t	compt;
	size_t	i;

	i = 0;
	compt = 0;
	while (i < ft_strlen(s))
	{
		if (i == 0 && s[i] != c)
			compt++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			compt++;
		i++;
	}
	return (compt);
}

static char		**ft_filler(char const *s, char c, char **tab)
{
	size_t		i;
	size_t		start;
	size_t		index;

	index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			tab[index] = ft_strsub(s, start, i - start);
			index++;
		}
	}
	tab[index] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_nbword(s, c) + 1))))
		return (NULL);
	return (ft_filler(s, c, tab));
}
