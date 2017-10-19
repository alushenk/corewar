/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 14:47:26 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:20:31 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_st(char *s, char **data, struct s_lol *st)
{
	struct s_ldi	l;
	char			*v;

	l.stars = "";
	if ((l.t = glgl(s, &v)) == NULL)
		return (NULL);
	l.i = 1;
	l.k = 0;
	if (st_1(&l, st, &v, data) == -1)
		return (NULL);
	if (l.t[l.i + 1] != NULL || l.t[l.i][l.k] != '\0')
		return (NULL);
	stars_arg(l.stars, &v);
	return (v);
}

char	**glgl(char *s, char **v)
{
	char	**t;
	char	*yoyo;

	*v = "03**";
	if (check_operation(s) == -1)
		return (NULL);
	yoyo = ft_strstr(s, "st ");
	t = ft_strsplit(yoyo, ' ');
	return (t);
}

int		st_1(struct s_ldi *l, struct s_lol *st, char **v, char **data)
{
	if ((*l).t[(*l).i][(*l).k] == 'r')
	{
		if (ldi_reg(l, v) == NULL)
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
	return (0);
}
