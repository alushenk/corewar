/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lld_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 15:41:52 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:28:00 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	**lld_1(char *s, char **v)
{
	char **t;
	char *yoyo;

	if (check_operation(s) == -1)
		return (NULL);
	if ((yoyo = ft_strstr(s, "lld ")) != NULL)
		*v = "0d**";
	else if ((yoyo = ft_strstr(s, "ld ")) != NULL)
		*v = "02**";
	t = ft_strsplit(yoyo, ' ');
	return (t);
}

int		dir_4(struct s_ldi *l, char **v, char **data, struct s_lol *st)
{
	char	*y;
	char	**r;
	int		t;

	((*l).k)++;
	if ((*l).t[(*l).i][(*l).k] == ':')
	{
		((*l).k)++;
		if ((t = ildi_2(l, st, &y)) == -1)
			return (-1);
		r = ft_strsplit((*st).lable, ' ');
		silka_4(v, data, st, t);
	}
	if (ft_isdigit((*l).t[(*l).i][(*l).k]) == 1
			|| (*l).t[(*l).i][(*l).k] == '-')
	{
		ldi_3(l, &y);
		*v = ft_strjoin(*v, pres_4(ft_atoi(y)));
	}
	(*l).stars = ft_strjoin((*l).stars, "10");
	return (1);
}

int		lldos(struct s_ldi *l, struct s_lol *st, char **v, char **data)
{
	if ((*l).t[(*l).i][(*l).k] == '%')
	{
		if (dir_4(l, v, data, st) == -1)
			return (-1);
	}
	else if (ft_isdigit((*l).t[(*l).i][(*l).k]) == 1
			|| (*l).t[(*l).i][(*l).k] == '-')
		ldi_ind(l, v);
	else if ((*l).t[(*l).i][(*l).k] == ':')
	{
		if (ldi_ind_1(l, v, data, st) == NULL)
			return (-1);
	}
	else
		return (-1);
	if (skip(l) == -1)
		return (-1);
	if ((*l).t[(*l).i][(*l).k] == 'r')
	{
		if (ldi_reg(l, v) == NULL)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
