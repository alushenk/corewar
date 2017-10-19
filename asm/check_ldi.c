/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:06:22 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 11:51:34 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_ldi(char *s, char **data, struct s_lol *st)
{
	struct s_ldi	l;
	char			*v;

	((*st).y)++;
	l.stars = "";
	if ((l.t = ldi_1(s, &v)) == NULL)
		return (NULL);
	l.i = 1;
	l.k = 0;
	if (short_ldi(&l, st, &v, data) == -1)
		return (NULL);
	if (short_ldi_2(&l, st, &v, data) == -1)
		return (NULL);
	if (l.t[l.i + 1] != NULL || l.t[l.i][l.k] != '\0')
		return (NULL);
	stars_arg(l.stars, &v);
	return (v);
}
