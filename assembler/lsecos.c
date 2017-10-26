/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsecos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:45:35 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/20 11:27:27 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		find_endl(int fd)
{
	int		i;
	char	*line;

	line = ft_strnew(10);
	i = -1;
	line[0] = ' ';
	while (line[0] == ' ' || line[0] == '\t')
	{
		if (lseek(fd, i, SEEK_END) > 0)
		{
			read(fd, line, 1);
		}
		else
			return (-1);
		i--;
	}
	if (line[0] == '\n')
		return (1);
	return (-1);
}
