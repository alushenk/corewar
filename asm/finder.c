/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:01:02 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 17:33:06 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		find_i(char **s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strstr(s[i], ".name ") != NULL)
	{
		while (ft_strstr(s[i], ".comment") == NULL)
			i++;
		while (s[i][ft_strlen(s[i]) - 1] != '"')
			i++;
		return (++i);
	}
	else
	{
		while (ft_strstr(s[i], ".name ") == NULL)
			i++;
		while (s[i][ft_strlen(s[i]) - 1] != '"')
			i++;
		return (++i);
	}
}
