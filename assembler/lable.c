/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lable.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 09:37:03 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/16 02:12:54 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	*pars_lable(char *s)
{
	char	*lable;
	char	*save;
	int		i;
	int		r;

	lable = "";
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ':' && islable(s, i) == 1)
		{
			dizaster(i, s, &r, &save);
			if (r == 0)
				return (NULL);
			lable = ft_strjoin(lable, save);
			lable = ft_strjoin(lable, " ");
		}
		i++;
	}
	return (lable);
}

void	dizaster(int i, char *s, int *r, char **save)
{
	int j;
	int y;
	int k;

	j = i;
	y = 0;
	while (s[j] != '\n')
	{
		j--;
		y++;
	}
	*save = (char *)malloc(sizeof(char) * (y));
	(*save)[y - 1] = '\0';
	j = i - 1;
	k = y - 2;
	while (y != 1)
	{
		(*save)[k] = s[j];
		j--;
		y--;
		k--;
	}
	*r = iscorect_lable(*save);
}

int		iscorect_lable(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (is_la(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		is_la(char c)
{
	int		i;
	char	*la;

	i = 0;
	la = "abcdefghijklmnopqrstuvwxyz_0123456789";
	while (la[i] != '\0')
	{
		if (la[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		islable(char *s, int i)
{
	if (s[i - 1] == '%' || s[i - 1] == ' '
			|| s[i - 1] == '\t' || s[i - 1] == ',')
		return (-1);
	else
		return (1);
}
