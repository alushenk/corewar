/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 23:48:56 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:16:59 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_zjmp(char *s, char **data, struct s_lol *st)
{
	char			*v;
	struct s_ldi	l;

	l.stars = "";
	if ((l.t = zm(s, &v)) == NULL)
		return (NULL);
	l.i = 1;
	l.k = 0;
	if (l.t[l.i][l.k] == '%')
	{
		if (ldi_dir(&l, &v, data, st) == NULL)
			return (NULL);
	}
	if (l.t[l.i + 1] != NULL || l.t[l.i][l.k] != '\0')
		return (NULL);
	stars_arg(l.stars, &v);
	return (v);
}
