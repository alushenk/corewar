/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:55:10 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/16 03:16:54 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		check_operation(char *str)
{
	char	*u;
	char	**s;
	int		i[2];
	int		j;
	char	**t;

	u = "live,lldi,ldi,lld,ld,sti,st,add,sub,and,xor,or,zjmp,lfork,fork";
	s = ft_strsplit(u, ',');
	t = ft_strsplit(str, ' ');
	i[0] = -1;
	i[1] = 0;
	while (s[++(i[0])] != NULL)
	{
		j = -1;
		while (t[++j] != NULL)
		{
			if (ft_strstr(t[j], s[i[0]]) != NULL
					&& ft_strlen(t[j]) == ft_strlen(s[i[0]]))
				(i[1])++;
		}
	}
	if (i[1] > 1)
		return (-1);
	return (1);
}
