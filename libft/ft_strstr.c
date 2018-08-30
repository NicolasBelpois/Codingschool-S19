/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:14:09 by nbelpois          #+#    #+#             */
/*   Updated: 2018/06/19 15:16:28 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *need)
{
	int	i;
	int	j;

	if (*need == '\0')
		return ((char*)hay);
	i = 0;
	while (hay[i])
	{
		j = 0;
		while (hay[i + j] == need[j])
		{
			j++;
			if (need[j] == '\0')
				return ((char*)hay + i);
		}
		i++;
	}
	return (NULL);
}
