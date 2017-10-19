/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kripto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 01:30:23 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:23:32 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

void	kripo(char *lable, char **data, struct s_lol *st)
{
	char	**t;
	char	*f;
	int		y;
	int		h;
	int		e;

	h = 0;
	t = ft_strsplit(lable, ' ');
	e = 4383;
	while ((*data)[++e] != '\0')
	{
		if ((*data)[e] == '(')
		{
			horos(&f, data, &y, e);
			gogo(&f, st, &h, y);
			y = -1;
			while (f[++y] != '\0')
			{
				(*data)[e] = f[y];
				e++;
			}
			h++;
		}
	}
}

void	gogo(char **f, struct s_lol *st, int *h, int y)
{
	char **r;

	r = ft_strsplit((*st).s, ' ');
	if (y > 3)
		*f = pres_4(((*st).a[ft_atoi(*f)] - ft_atoi(r[*h])) / 2);
	else
		*f = pres(((*st).a[ft_atoi(*f)] - ft_atoi(r[*h])) / 2);
}

void	horos(char **f, char **data, int *y, int e)
{
	int		j;

	j = e;
	*y = 0;
	j++;
	*f = (char *)malloc(sizeof(char) * 10);
	while (ft_isdigit((*data)[j]))
	{
		(*f)[*y] = (*data)[j];
		(*y)++;
		j++;
	}
	*y = 0;
	while ((*data)[j] == '?')
	{
		j++;
		(*y)++;
	}
}
