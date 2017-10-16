/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_all_coment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 22:02:19 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/10 04:29:20 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		del_all_coment(char **s)
{
	int i;

	i = -1;
	while ((*s)[++i] != '\0')
	{
		if ((*s)[i] == '"')
		{
			i++;
			while ((*s)[i] != '"')
			{
				if ((*s)[i] == '\n' || (*s)[i] == '\0')
					return (-1);
				i++;
			}
		}
		if ((*s)[i] == '#' || (*s)[i] == ';')
		{
			while ((*s)[i] != '\n' && (*s)[i] != '\0')
			{
				(*s)[i] = ' ';
				i++;
			}
		}
	}
	return (0);
}
