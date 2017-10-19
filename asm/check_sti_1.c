/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sti_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:42:29 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:28:32 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	**sti_1(char *s, char **v)
{
	char **t;
	char *yoyo;

	*v = "0b**";
	if (check_operation(s) == -1)
		return (NULL);
	yoyo = ft_strstr(s, "sti ");
	t = ft_strsplit(yoyo, ' ');
	return (t);
}

int		short_sti(struct s_ldi *l, struct s_lol *st, char **v, char **data)
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
	if (short_ldi(l, st, v, data) == -1)
		return (-1);
	if ((*l).t[(*l).i][(*l).k] == '%')
	{
		if (ldi_dir(l, v, data, st) == NULL)
			return (-1);
	}
	else if ((*l).t[(*l).i][(*l).k] == 'r')
	{
		if (ldi_reg(l, v) == NULL)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
