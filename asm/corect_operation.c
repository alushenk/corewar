/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corect_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 11:41:04 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/16 04:15:20 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		*kk(char *s, char *lable, char **data, struct lol *st)
{
	int		i;
	char	**str;
	char	**t;

	t = ft_strsplit(lable, ' ');
	i = 0;
	while (t[i] != NULL)
		i++;
	(*st).s = "";
	(*st).a = (int *)malloc(sizeof(int) * 4000);
	str = ft_strsplit(s, '\n');
	i = 2;
	while (str[i] != NULL)
	{
		check_lable_is(lable, str[i], data, st);
		if (find_operation(str[i], data, st) == -1)
			return (NULL);
		i++;
	}
	return ((*st).a);
}

int		find_operation_1(char *s, char **data, struct lol *st)
{
	char *r;

	if (ft_strstr(s, "live ") != NULL)
	{
		if ((r = check_arguments_live(s, data, st)) == NULL)
			return (-1);
		*data = ft_strjoin(*data, r);
		return (1);
	}
	if (ft_strstr(s, "ldi ") != NULL || ft_strstr(s, "lldi ") != NULL)
	{
		if ((r = check_arguments_ldi(s, data, st)) == NULL)
			return (-1);
		*data = ft_strjoin(*data, r);
		return (1);
	}
	if ((ft_strstr(s, "lld ") != NULL) || (ft_strstr(s, "ld ") != NULL))
	{
		if ((r = check_arguments_lld(s, data, st)) == NULL)
			return (-1);
		*data = ft_strjoin(*data, r);
		return (1);
	}
	return (0);
}

int		find_operation_2(char *s, char **data, struct lol *st)
{
	char *r;

	if (ft_strstr(s, "sti ") != NULL)
	{
		if ((r = check_arguments_sti(s, data, st)) == NULL)
			return (-1);
		*data = ft_strjoin(*data, r);
		return (1);
	}
	if (ft_strstr(s, "st ") != NULL)
	{
		if ((r = check_arguments_st(s, data, st)) == NULL)
			return (-1);
		*data = ft_strjoin(*data, r);
		return (1);
	}
	if (ft_strstr(s, "add ") != NULL || ft_strstr(s, "sub ") != NULL)
	{
		if ((r = check_arguments_add(s)) == NULL)
			return (-1);
		*data = ft_strjoin(*data, r);
		return (1);
	}
	return (0);
}

int		find_operation_3(char *s, char **data, struct lol *st)
{
	char *r;

	if (ft_strstr(s, "and ") != NULL || ft_strstr(s, "or ") != NULL ||
			ft_strstr(s, "xor ") != NULL)
	{
		if ((r = check_arguments_and(s, data, st)) == NULL)
			return (-1);
		*data = ft_strjoin(*data, r);
		return (1);
	}
	if (ft_strstr(s, "zjmp ") != NULL || ft_strstr(s, "fork ") != NULL
			|| ft_strstr(s, "lfork ") != NULL)
	{
		if ((r = check_arguments_zjmp(s, data, st)) == NULL)
			return (-1);
		*data = ft_strjoin(*data, r);
		return (1);
	}
	return (0);
}

int		find_operation(char *s, char **data, struct lol *st)
{
	char	*r;

	if (find_operation_1(s, data, st) == -1)
		return (-1);
	if (find_operation_2(s, data, st) == -1)
		return (-1);
	if (find_operation_3(s, data, st) == -1)
		return (-1);
	if (ft_strstr(s, "aff ") != NULL)
	{
		if ((r = check_arguments_aff(s)) == NULL)
			return (-1);
		*data = ft_strjoin(*data, r);
		return (1);
	}
	else
		return (0);
}
