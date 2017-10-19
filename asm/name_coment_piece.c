/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_coment_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:53:36 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 14:45:18 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		name_coment(char *s, char **data)
{
	int i;

	i = 0;
	if (mane_2(&i, s, data) == -1)
		return (-1);
	if (come_2(&i, s, data) == -1)
		return (-1);
	while (s[++i] != '\n')
	{
		if (!(s[i] == ' ' || s[i] == '\t'))
			return (-1);
	}
	return (i);
}

char	*name_trans(int *i, char *s)
{
	char	*name;
	int		k;

	*i = *i + 5;
	while (s[++(*i)] != '"')
	{
		if (!(s[*i] == ' ' || s[*i] == '\t'))
			return (NULL);
	}
	k = 0;
	name = ft_strnew(PROG_NAME_LENGTH + 2);
	name[PROG_NAME_LENGTH + 1] = '\0';
	while (s[++(*i)] != '"')
	{
		if (k > PROG_NAME_LENGTH - 1)
			return (NULL);
		name[k] = s[*i];
		k++;
	}
	while (s[++(*i)] != '\n' && s[*i] != '\0')
	{
		if (!(s[*i] == ' ' || s[*i] == '\t'))
			return (NULL);
	}
	return (name);
}
