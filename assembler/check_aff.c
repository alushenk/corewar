/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:36:42 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/18 14:22:56 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*check_arguments_aff(char *s)
{
	struct s_ldi	l;
	char			*v;

	l.stars = "";
	if ((l.t = sti_1(s, &v)) == NULL)
		return (NULL);
	l.i = 1;
	l.k = 0;
	if (l.t[l.i][l.k] == 'r')
	{
		if (ldi_reg(&l, &v) == NULL)
			return (NULL);
	}
	else
		return (NULL);
	if (l.t[l.i + 1] != NULL || l.t[l.i][l.k] != '\0')
		return (NULL);
	stars_arg(l.stars, &v);
	return (v);
}

char	**ggg(char *s, char **v)
{
	char	**t;
	char	*yoyo;

	*v = "10**";
	if (check_operation(s) == -1)
		return (NULL);
	yoyo = ft_strstr(s, "aff ");
	t = ft_strsplit(yoyo, ' ');
	return (t);
}
