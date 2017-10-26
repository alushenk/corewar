/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corect_operation_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:38:43 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 12:06:47 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		find_operation_4(char *s, char **data, struct s_lol *st, int *a)
{
	char *r;

	if ((ft_strstr(s, "lld ") != NULL) || (ft_strstr(s, "ld ") != NULL))
	{
		((*st).y)++;
		if ((r = check_arguments_lld(s, data, st)) == NULL)
		{
			if (ft_strstr(s, "lld ") != NULL)
				*a = -24;
			else
				*a = -25;
			return (-1);
		}
		*data = ft_strjoin(*data, r);
	}
	return (0);
}

int		find_operation_5(char *s, char **data, struct s_lol *st, int *a)
{
	char *r;

	if (ft_strstr(s, "add ") != NULL || ft_strstr(s, "sub ") != NULL)
	{
		((*st).y)++;
		if ((r = check_arguments_add(s)) == NULL)
		{
			if (ft_strstr(s, "add ") != NULL)
				*a = -28;
			else
				*a = -29;
			return (-1);
		}
		*data = ft_strjoin(*data, r);
	}
	return (0);
}

int		find_operation_6(char *s, char **data, struct s_lol *st, int *a)
{
	char *r;

	if (ft_strstr(s, "zjmp ") != NULL || ft_strstr(s, "fork ") != NULL
			|| ft_strstr(s, "lfork ") != NULL)
	{
		((*st).y)++;
		if ((r = check_arguments_zjmp(s, data, st)) == NULL)
		{
			if (ft_strstr(s, "zjmp ") != NULL)
				*a = -33;
			else if (ft_strstr(s, "lfork ") != NULL)
				*a = -34;
			else
				*a = -35;
			return (-1);
		}
		*data = ft_strjoin(*data, r);
	}
	return (0);
}

int		find_operation_7(char *s, char **data, struct s_lol *st, int *a)
{
	char *r;

	if (ft_strstr(s, "aff ") != NULL)
	{
		((*st).y)++;
		if ((r = check_arguments_aff(s)) == NULL)
		{
			*a = -36;
			return (-1);
		}
		*data = ft_strjoin(*data, r);
		return (1);
	}
	return (0);
}
