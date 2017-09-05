/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:28:06 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/04 17:11:59 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *tmp1, const void *tmp2, size_t len)
{
	size_t	i;

	if (tmp1 >= tmp2)
	{
		while (len != 0)
		{
			len--;
			*((unsigned char*)tmp1 + len) = *((unsigned char*)tmp2 + len);
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char*)tmp1 + i) = *((unsigned char*)tmp2 + i);
			i++;
		}
	}
	return (tmp1);
}
