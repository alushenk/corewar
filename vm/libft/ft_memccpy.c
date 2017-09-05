/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:51:02 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/05 15:23:11 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp1;

	temp = (unsigned char*)dst;
	temp1 = (unsigned char*)src;
	while (n != 0)
	{
		*temp = *temp1;
		if (*temp1 == (unsigned char)c)
			return (temp + 1);
		temp++;
		temp1++;
		n--;
	}
	return (NULL);
}
