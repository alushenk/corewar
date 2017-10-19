/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:18:30 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:22:30 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_lld(char *s, char **data, struct s_lol *st)
{
	struct s_ldi	l;
	char			*v;

	l.stars = "";
	if ((l.t = lld_1(s, &v)) == NULL)
		return (NULL);
	l.i = 1;
	l.k = 0;
	if (lldos(&l, st, &v, data) == -1)
		return (NULL);
	if (l.t[l.i + 1] != NULL || l.t[l.i][l.k] != '\0')
		return (NULL);
	stars_arg(l.stars, &v);
	return (v);
}
