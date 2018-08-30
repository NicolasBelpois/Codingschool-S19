/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:23:52 by nbelpois          #+#    #+#             */
/*   Updated: 2018/06/21 10:38:08 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*psrc;
	unsigned char	*pdst;
	unsigned char	x;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	x = c;
	while (n-- > 0)
		if ((*pdst++ = *psrc++) == x)
			return (pdst);
	return (NULL);
}
