/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 21:55:36 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:16:27 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_and(char *s, char **data, struct s_lol *st)
{
	struct s_ldi	l;
	char			*v;

	l.stars = "";
	if ((l.t = and_1(s, &v)) == NULL)
		return (NULL);
	l.i = 1;
	l.k = 0;
	if (and_2(&l, &v, data, st) == -1)
		return (NULL);
	if (and_2(&l, &v, data, st) == -1)
		return (NULL);
	if (l.t[l.i][l.k] == 'r')
	{
		if (ldi_reg(&l, &v) == NULL)
			return (NULL);
	}
	if (l.t[l.i + 1] != NULL || l.t[l.i][l.k] != '\0')
		return (NULL);
	stars_arg(l.stars, &v);
	return (v);
}
