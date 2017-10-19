/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ldi_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:50:02 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:27:10 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		skip(struct s_ldi *l)
{
	if ((*l).t[(*l).i][(*l).k] == '\0')
	{
		((*l).i)++;
		(*l).k = 0;
	}
	if ((*l).t[(*l).i] == NULL || (*l).t[(*l).i][(*l).k] != ',')
		return (-1);
	((*l).k)++;
	if ((*l).t[(*l).i][(*l).k] == '\0')
	{
		((*l).i)++;
		(*l).k = 0;
	}
	if ((*l).t[(*l).i] == NULL)
		return (-1);
	return (0);
}

int		short_ldi(struct s_ldi *l, struct s_lol *st, char **v, char **data)
{
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
	else if (ft_isdigit((*l).t[(*l).i][(*l).k]) == 1
			|| (*l).t[(*l).i][(*l).k] == '-')
	{
		ldi_ind(l, v);
	}
	else if ((*l).t[(*l).i][(*l).k] == ':')
	{
		if (ldi_ind_1(l, v, data, st) == NULL)
			return (-1);
	}
	else
		return (-1);
	return (skip(l));
}

int		short_ldi_2(struct s_ldi *l, struct s_lol *st, char **v, char **data)
{
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
	if (skip(l) == -1)
		return (-1);
	if ((*l).t[(*l).i][(*l).k] == 'r')
	{
		if (ldi_reg(l, v) == NULL)
			return (-1);
	}
	return (0);
}
