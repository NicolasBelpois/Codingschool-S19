/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 09:04:11 by nbelpois          #+#    #+#             */
/*   Updated: 2018/06/21 10:35:51 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	temp = (void*)malloc(sizeof(*temp) * size);
	if (temp == NULL)
		return (NULL);
	ft_memset(temp, 0, size);
	return (temp);
}
