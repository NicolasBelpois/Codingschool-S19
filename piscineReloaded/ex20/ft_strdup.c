/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:15:35 by nbelpois          #+#    #+#             */
/*   Updated: 2018/06/13 12:40:37 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*temp;
	int		len;
	int		i;

	len = 0;
	while (src[len] != '\0')
		len++;
	temp = malloc(sizeof(*src) * (len + 1));
	i = 0;
	temp[len] = '\0';
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	return (temp);
}
