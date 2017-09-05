/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:21:46 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/05 15:23:01 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp1;
	size_t			i;

	temp = (unsigned char*)dst;
	temp1 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		temp[i] = temp1[i];
		i++;
	}
	return (temp);
}
