/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_n_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 12:41:07 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/20 13:55:03 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		doubles(char *s)
{
	char *t;
	char *y;

	if ((t = ft_strstr(s, ".name")) == NULL)
		return (-1);
	t = t + 5;
	if (ft_strstr(t, ".name") != NULL)
		return (-1);
	if ((y = ft_strstr(s, ".comment")) == NULL)
		return (-1);
	y = y + 8;
	if (ft_strstr(y, ".comment") != NULL)
		return (-1);
	return (1);
}
