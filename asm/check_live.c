/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 03:33:05 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:19:05 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_live(char *s, char **data, struct s_lol *st)
{
	struct s_pop	p;
	char			**t;
	int				i;
	char			*v;

	v = "01";
	i = 1;
	p.i = 0;
	if ((t = live_1(s)) == NULL)
		return (NULL);
	if (t[i][p.i] == '%')
	{
		p.i++;
		p.s = t[i];
		if (live_2(&p, data, st, &v) == -1)
			return (NULL);
		live_3(t, &i, &p, &v);
		if (t[i + 1] != NULL || t[i][p.i] != '\0')
			return (NULL);
	}
	else
		return (NULL);
	return (v);
}

char	**live_1(char *s)
{
	int		k;
	char	*yoyo;
	char	**t;

	k = 0;
	if (check_operation(s) == -1)
		return (NULL);
	yoyo = ft_strstr(s, "live ");
	t = ft_strsplit(yoyo, ' ');
	while (t[k] != NULL)
		k++;
	if (k != 2)
		return (NULL);
	return (t);
}

void	live_3(char **t, int *i, struct s_pop *p, char **v)
{
	char	*dig;
	int		o;
	char	*y;

	if (ft_isdigit(t[*i][(*p).i]) == 1 || t[*i][(*p).i] == '-')
	{
		y = (char *)malloc(sizeof(char) * 100);
		o = 0;
		if (t[*i][(*p).i] == '-')
		{
			y[o] = t[*i][(*p).i];
			o++;
			((*p).i)++;
		}
		while (ft_isdigit(t[*i][(*p).i]) == 1)
		{
			y[o] = t[*i][(*p).i];
			((*p).i)++;
			o++;
		}
		dig = pres_4(ft_atoi(y));
		*v = ft_strjoin(*v, dig);
	}
}

int		live_2(struct s_pop *p, char **data, struct s_lol *st, char **v)
{
	int		o;
	char	**r;
	char	*y;
	int		t;

	if ((*p).s[(*p).i] == ':')
	{
		(*p).i++;
		y = (char *)malloc(sizeof(char) * 100);
		o = 0;
		while (is_la((*p).s[(*p).i]))
		{
			y[o] = (*p).s[(*p).i];
			(*p).i++;
			o++;
		}
		y[o] = '\0';
		r = ft_strsplit((*st).lable, ' ');
		if ((t = live_1_1(r, y)) == -1)
			return (-1);
		silka_4(v, data, st, t);
	}
	else if ((*p).s[(*p).i] == '\0')
		return (-1);
	return (0);
}

int		live_1_1(char **r, char *y)
{
	int o;
	int c;
	int t;

	o = 0;
	c = 0;
	t = 0;
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
