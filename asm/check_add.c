/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 15:04:30 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:21:29 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_add(char *s)
{
	char			*v;
	struct s_ldi	l;

	l.stars = "";
	if ((l.t = add_1(s, &v)) == NULL)
		return (NULL);
	l.i = 1;
	l.k = 0;
	if (add_2(&l, &v) == -1)
		return (NULL);
	if (l.t[l.i + 1] != NULL || l.t[l.i][l.k] != '\0')
		return (NULL);
	stars_arg(l.stars, &v);
	return (v);
}

char	**add_1(char *s, char **v)
{
	char	*yoyo;
	char	**t;

	if (check_operation(s) == -1)
		return (NULL);
	if ((yoyo = ft_strstr(s, "add ")) != NULL)
		*v = "04**";
	else if ((yoyo = ft_strstr(s, "sub ")) != NULL)
		*v = "05**";
	t = ft_strsplit(yoyo, ' ');
	return (t);
}

int		add_2(struct s_ldi *l, char **v)
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
	else
		return (-1);
	if (down(l, v) == -1)
		return (-1);
	else
		return (0);
}

int		down(struct s_ldi *l, char **v)
{
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
