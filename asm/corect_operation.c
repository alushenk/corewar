/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corect_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 11:41:04 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 17:16:27 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		*kk(char *s, int *a, char **data, struct s_lol *st)
{
	int		i;
	char	**str;
	char	**t;

	t = ft_strsplit((*st).lable, ' ');
	i = 0;
	*a = -1;
	while (t[i] != NULL)
		i++;
	(*st).s = "";
	(*st).a = (int *)malloc(sizeof(int) * 4000);
	str = ft_strsplit(s, '\n');
	i = find_i(str);
	while (str[i] != NULL)
	{
		check_lable_is((*st).lable, str[i], data, st);
		if (find_operation(str[i], data, st, a) == -1)
			return (NULL);
		i++;
	}
	return ((*st).a);
}

int		find_operation_1(char *s, char **data, struct s_lol *st, int *a)
{
	char *r;

	if (ft_strstr(s, "live ") != NULL)
	{
		((*st).y)++;
		if ((r = check_arguments_live(s, data, st)) == NULL)
		{
			*a = -21;
			return (-1);
		}
		*data = ft_strjoin(*data, r);
	}
	else if (ft_strstr(s, "ldi ") != NULL || ft_strstr(s, "lldi ") != NULL)
	{
		if ((r = check_arguments_ldi(s, data, st)) == NULL)
		{
			if (ft_strstr(s, "ldi ") != NULL)
				*a = -22;
			else
				*a = -23;
			return (-1);
		}
		*data = ft_strjoin(*data, r);
	}
	return (0);
}

int		find_operation_2(char *s, char **data, struct s_lol *st, int *a)
{
	char *r;

	if (ft_strstr(s, "sti ") != NULL)
	{
		((*st).y)++;
		if ((r = check_arguments_sti(s, data, st)) == NULL)
		{
			*a = -26;
			return (-1);
		}
		*data = ft_strjoin(*data, r);
		return (1);
	}
	if (ft_strstr(s, "st ") != NULL)
	{
		((*st).y)++;
		if ((r = check_arguments_st(s, data, st)) == NULL)
		{
			*a = -27;
			return (-1);
		}
		*data = ft_strjoin(*data, r);
		return (1);
	}
	return (0);
}

int		find_operation_3(char *s, char **data, struct s_lol *st, int *a)
{
	char *r;

	if (ft_strstr(s, "and ") != NULL || ft_strstr(s, "or ") != NULL ||
			ft_strstr(s, "xor ") != NULL)
	{
		((*st).y)++;
		if ((r = check_arguments_and(s, data, st)) == NULL)
		{
			if (ft_strstr(s, "and ") != NULL)
				*a = -30;
			else if (ft_strstr(s, "xor ") != NULL)
				*a = -31;
			else
				*a = -32;
			return (-1);
		}
		*data = ft_strjoin(*data, r);
		return (1);
	}
	return (0);
}

int		find_operation(char *s, char **data, struct s_lol *st, int *a)
{
	(*st).y = 0;
	if (find_operation_1(s, data, st, a) == -1)
		return (-1);
	if (find_operation_4(s, data, st, a) == -1)
		return (-1);
	if (find_operation_2(s, data, st, a) == -1)
		return (-1);
	if (find_operation_5(s, data, st, a) == -1)
		return (-1);
	if (find_operation_3(s, data, st, a) == -1)
		return (-1);
	if (find_operation_6(s, data, st, a) == -1)
		return (-1);
	if (find_operation_7(s, data, st, a) == -1)
		return (-1);
	if ((*st).y == 0)
	{
		if (or_is_lable((*st).lable, s) == -1)
			return (-1);
		else
			return (0);
	}
	else
		return (0);
}
