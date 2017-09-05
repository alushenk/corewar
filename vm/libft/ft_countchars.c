/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:21:35 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/01 18:35:40 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countchars(char *str, char c)
{
	char	*tmp;
	int		i;

	if (!str)
		return (0);
	tmp = str;
	i = 0;
	while (*tmp != c && *tmp != '\0')
	{
		tmp++;
		i++;
	}
	return (i);
}
