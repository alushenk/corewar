/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:43:27 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/01 17:14:03 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	char	*tmp;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	tmp = (char*)s;
	if ((fresh = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (i < len)
	{
		fresh[i] = tmp[start];
		i++;
		start++;
	}
	fresh[i] = '\0';
	return (fresh);
}
