/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_coment_piece_copy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 04:28:05 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 13:04:40 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		chenos(char *s, int *i, int *k)
{
	while (s[*i] == ' ' || s[*i] == '\n')
		(*i)++;
	if (s[*i] != '.' || s[*i + 1] != 'c' || s[*i + 2] != 'o' || s[*i + 3] != 'm'
			|| s[*i + 4] != 'm' || s[*i + 5] != 'e'
			|| s[*i + 6] != 'n' || s[*i + 7] != 't')
		return (-1);
	*i = *i + 8;
	while (s[*i] != '"')
	{
		if (!(s[*i] == ' '))
			return (-1);
		(*i)++;
	}
	*k = 0;
	return (0);
}

int		cle_1(char *s, int *i, int *k, char *coment)
{
	while (s[++(*i)] != '"')
	{
		if (*k > COMMENT_LENGTH - 1)
			return (-1);
		coment[*k] = s[*i];
		(*k)++;
	}
	while (s[++(*i)] != '\n')
	{
		if (s[*i] == '#')
		{
			while (s[*i] != '\n' && s[*i] != '\0')
				(*i)++;
			--(*i);
		}
		if (!(s[*i] == ' '))
			return (-1);
	}
	while (s[++(*i)] == ' ' || s[*i] == '\n')
	{
	}
	return (0);
}

int		name_coment_1(char *s, char **data)
{
	int		i;
	int		k;
	char	*name;
	char	*coment;

	i = 0;
	if (chenos(s, &i, &k) == -1)
		return (-1);
	coment = ft_strnew(COMMENT_LENGTH + 2);
	coment[COMMENT_LENGTH + 1] = '\0';
	if (cle_1(s, &i, &k, coment) == -1)
		return (-1);
	if (s[i] == '.' && s[i + 1] == 'n' && s[i + 2] == 'a' && s[i + 3] == 'm'
			&& s[i + 4] == 'e')
	{
		name = name_trans(&i, s);
		if (name == NULL)
			return (-1);
		transform_name(name, data);
	}
	else
		return (-1);
	transform_coment(coment, data);
	return (i);
}
