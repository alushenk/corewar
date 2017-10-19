/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ldi_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:38:45 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:25:26 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	**ldi_1(char *s, char **v)
{
	char **t;
	char *yoyo;

	if (check_operation(s) == -1)
		return (NULL);
	if ((yoyo = ft_strstr(s, "lldi ")) != NULL)
		*v = "0e**";
	else if ((yoyo = ft_strstr(s, "ldi ")) != NULL)
		*v = "0a**";
	t = ft_strsplit(yoyo, ' ');
	return (t);
}

char	*ldi_dir(struct s_ldi *l, char **v, char **data, struct s_lol *st)
{
	char	*y;
	char	**r;
	int		t;

	((*l).k)++;
	if ((*l).t[(*l).i][(*l).k] == ':')
	{
		((*l).k)++;
		if ((t = ildi_2(l, st, &y)) == -1)
			return (NULL);
		r = ft_strsplit((*st).lable, ' ');
		silka(v, data, st, t);
	}
	if (ft_isdigit((*l).t[(*l).i][(*l).k]) == 1
			|| (*l).t[(*l).i][(*l).k] == '-')
	{
		ldi_3(l, &y);
		*v = ft_strjoin(*v, pres(ft_atoi(y)));
	}
	(*l).stars = ft_strjoin((*l).stars, "10");
	return ((*l).stars);
}

int		ildi_2(struct s_ldi *l, struct s_lol *st, char **y)
{
	int		o;
	char	**r;

	*y = (char *)malloc(sizeof(char) * 100);
	o = 0;
	while (is_la((*l).t[(*l).i][(*l).k]))
	{
		(*y)[o] = (*l).t[(*l).i][(*l).k];
		((*l).k)++;
		o++;
	}
	(*y)[o] = '\0';
	r = ft_strsplit((*st).lable, ' ');
	return (ldi_4(r, y));
}

void	ldi_3(struct s_ldi *l, char **y)
{
	int o;

	*y = (char *)malloc(sizeof(char) * 100);
	o = 0;
	if ((*l).t[(*l).i][(*l).k] == '-')
	{
		(*y)[o] = (*l).t[(*l).i][(*l).k];
		o++;
		((*l).k)++;
	}
	while (ft_isdigit((*l).t[(*l).i][(*l).k]) == 1)
	{
		(*y)[o] = ((*l).t)[(*l).i][(*l).k];
		((*l).k)++;
		o++;
	}
}

int		ldi_4(char **r, char **y)
{
	int o;
	int c;
	int t;

	o = -1;
	c = 0;
	t = 0;
	while (r[++o] != NULL)
	{
		if (ft_strcmp(r[o], *y) == 0)
		{
			t = o;
			c++;
		}
	}
	if (c == 0)
		return (-1);
	return (t);
}
