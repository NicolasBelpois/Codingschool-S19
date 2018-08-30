/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 10:13:39 by nbelpois          #+#    #+#             */
/*   Updated: 2018/06/19 13:47:28 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strj = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (strj == NULL)
		return (NULL);
	ft_strcpy(strj, s1);
	ft_strcat(strj, s2);
	return (strj);
}
