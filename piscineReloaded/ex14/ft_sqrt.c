/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:56:11 by nbelpois          #+#    #+#             */
/*   Updated: 2018/06/12 11:23:55 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int result;

	if (nb <= 0)
		return (0);
	result = 1;
	while ((result * result) < nb)
		result++;
	if (result * result == nb)
		return (result);
	return (0);
}
