/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:06:22 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/14 15:48:38 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_ldi(char *s, char **data, struct lol *st)
{
	struct ldi	l;
	char		*v;

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
