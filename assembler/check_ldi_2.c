/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ldi_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 19:26:12 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:26:19 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*ldi_reg(struct s_ldi *l, char **v)
{
	char	*dig;
	char	*y;
	int		o;

	((*l).k)++;
	y = (char *)malloc(sizeof(char) * 100);
	o = 0;
	while (ft_isdigit((*l).t[(*l).i][(*l).k]) == 1)
	{
		y[o] = (*l).t[(*l).i][(*l).k];
		(*l).k++;
		o++;
	}
	if (ft_atoi(y) < 0 || ft_atoi(y) > 99)
		return (NULL);
	dig = ft_itoa_base(ft_atoi(y), 16);
	if (ft_strlen(dig) == 1)
		*v = ft_strjoin(*v, "0");
	*v = ft_strjoin(*v, dig);
	(*l).stars = ft_strjoin((*l).stars, "01");
	return ((*l).stars);
}

void	ldi_ind(struct s_ldi *l, char **v)
{
	int		o;
	char	*y;

	y = (char *)malloc(sizeof(char) * 100);
	o = 0;
	if ((*l).t[(*l).i][(*l).k] == '-')
	{
		y[o] = (*l).t[(*l).i][(*l).k];
		o++;
		(*l).k++;
	}
	while (ft_isdigit((*l).t[(*l).i][(*l).k]) == 1)
	{
		y[o] = (*l).t[(*l).i][(*l).k];
		((*l).k)++;
		o++;
	}
	*v = ft_strjoin(*v, pres(ft_atoi(y)));
	(*l).stars = ft_strjoin((*l).stars, "11");
}

char	*ldi_ind_1(struct s_ldi *l, char **v, char **data, struct s_lol *st)
{
	int		o;
	int		t;
	char	*y;
	char	**r;

	(*l).k++;
	y = (char *)malloc(sizeof(char) * 100);
	o = 0;
	while (is_la((*l).t[(*l).i][(*l).k]))
	{
		y[o] = (*l).t[(*l).i][(*l).k];
		(*l).k++;
		o++;
	}
	y[o] = '\0';
	r = ft_strsplit((*st).lable, ' ');
	if ((t = ldi_ind_2(r, y)) == -1)
		return (NULL);
	silka(v, data, st, t);
	(*l).stars = ft_strjoin((*l).stars, "11");
	return ((*l).stars);
}

int		ldi_ind_2(char **r, char *y)
{
	int o;
	int c;
	int t;

	t = 0;
	o = 0;
	c = 0;
	while (r[o] != NULL)
	{
		if (ft_strcmp(r[o], y) == 0)
		{
			t = o;
			c++;
		}
		o++;
	}
	if (c == 0)
		return (-1);
	return (t);
}
