/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 12:32:41 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 10:59:47 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		open_s_file(char *s, char **t)
{
	int		fd;
	char	*line;
	int		k;
	int		a;
	int		p;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (-1);
	p = 0;
	while ((a = get_next_line(fd, &line)) != 0)
	{
		k = ft_strlen(line);
		if (k != 0)
		{
			line = changes(line);
			*t = ft_strjoin(*t, line);
			*t = ft_strjoin(*t, "\n");
		}
		p++;
	}
	return (0);
}
