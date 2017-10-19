/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 19:37:47 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:29:02 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	**and_1(char *s, char **v)
{
	char	**t;
	char	*yoyo;

	if (check_operation(s) == -1)
		return (NULL);
	if ((yoyo = ft_strstr(s, "and ")) != NULL)
		*v = "06**";
	else if ((yoyo = ft_strstr(s, "xor ")) != NULL)
		*v = "08**";
	else if ((yoyo = ft_strstr(s, "or ")) != NULL)
		*v = "07**";
	t = ft_strsplit(yoyo, ' ');
	return (t);
}

int		and_2(struct s_ldi *l, char **v, char **data, struct s_lol *st)
{
	if ((*l).t[(*l).i][(*l).k] == '%')
	{
		if (dir_4(l, v, data, st) == -1)
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
