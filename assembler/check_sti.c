/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:26:35 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:15:56 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_sti(char *s, char **data, struct s_lol *st)
{
	struct s_ldi	l;
	char			*v;

	l.stars = "";
	if ((l.t = sti_1(s, &v)) == NULL)
		return (NULL);
	l.i = 1;
	l.k = 0;
	if (short_sti(&l, st, &v, data) == -1)
		return (NULL);
	if (l.t[l.i + 1] != NULL || l.t[l.i][l.k] != '\0')
		return (NULL);
	stars_arg(l.stars, &v);
	return (v);
}
