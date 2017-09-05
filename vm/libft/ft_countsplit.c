/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:44:21 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/01 18:35:19 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countsplit(char *str, char c)
{
	char	*temp;
	int		count;

	if (!str)
		return (0);
	temp = str;
	count = 0;
	temp = ft_runchar(temp, c);
	while (*temp != '\0')
	{
		temp = ft_runstr(temp, c);
		temp = ft_runchar(temp, c);
		count++;
	}
	return (count);
}
