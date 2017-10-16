/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 00:06:30 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 18:50:42 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

void	check_lable_is(char *lable, char *str, char **data, struct lol *st)
{
	char	**t;
	int		i;
	int		j;
	char	**y;

	t = ft_strsplit(lable, ' ');
	i = 4384;
	j = 0;
	while ((*data)[i] != '\0')
	{
		i++;
		j++;
	}
	i = 0;
	while (t[i] != NULL)
	{
		y = ft_strsplit(str, ':');
		if (strstr(y[0], t[i]) != NULL && is_normas(y[0], t[i]))
		{
			(*st).a[i] = j;
			return ;
		}
		i++;
	}
	(*st).a[i] = -1;
}

int		is_normas(char *s, char *t)
{
	while (*s == ' ' || *s == '\t')
		s++;
	if (ft_strcmp(s, t) == 0)
		return (1);
	else
		return (0);
}
