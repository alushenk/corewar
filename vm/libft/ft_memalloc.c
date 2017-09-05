/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:04:31 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/01 18:33:44 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*temp;
	unsigned char	*strtemp;
	size_t			i;

	i = 0;
	if ((temp = (void*)malloc(size)) == NULL)
		return (NULL);
	strtemp = temp;
	while (i < size)
	{
		strtemp[i] = 0;
		i++;
	}
	return (temp);
}
