/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 18:03:56 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 14:41:52 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		mane_2(int *i, char *s, char **data)
{
	char *name;

	while (s[*i] == ' ' || s[*i] == '\n')
		(*i)++;
	if (s[*i] == '.' && s[*i + 1] == 'n' && s[*i + 2] == 'a' && s[*i + 3] == 'm'
			&& s[*i + 4] == 'e')
	{
		if ((name = name_trans(i, s)) == NULL)
			return (-1);
		transform_name(name, data);
	}
	else
		return (-1);
	(*i)++;
	while (s[*i] == ' ' || s[*i] == '\n')
		(*i)++;
	return (0);
}

int		come_2(int *i, char *s, char **data)
{
	char	*coment;
	int		k;

	if (s[*i] != '.' || s[*i + 1] != 'c' || s[*i + 2] != 'o' || s[*i + 3] != 'm'
			|| s[*i + 4] != 'm' || s[*i + 5] != 'e' ||
			s[*i + 6] != 'n' || s[*i + 7] != 't')
		return (-1);
	*i = *i + 8;
	while (s[*i] != '"')
	{
		if (!(s[*i] == ' ' || s[*i] == '\t'))
			return (-1);
		(*i)++;
	}
	k = -1;
	coment = ft_strnew(COMMENT_LENGTH + 2);
	coment[COMMENT_LENGTH + 1] = '\0';
	while (s[++(*i)] != '"')
	{
		if (++k > COMMENT_LENGTH - 1)
			return (-1);
		coment[k] = s[*i];
	}
	transform_coment(coment, data);
	return (0);
}
