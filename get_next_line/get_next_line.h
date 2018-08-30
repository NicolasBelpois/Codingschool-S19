/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelpois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:12:05 by nbelpois          #+#    #+#             */
/*   Updated: 2018/08/23 12:15:33 by nbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "libft.h"
# include <limits.h>

int		get_next_line(const int fd, char **line);

#endif
