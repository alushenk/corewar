/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 20:11:42 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/05 15:26:22 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*a;
	char	*b;

	b = (char*)to_find;
	if (*b == '\0')
		return ((char*)str);
	while (*str != '\0')
	{
		if (*str == *b)
		{
			a = (char*)str;
			while (*a == *b || *b == '\0')
			{
				if (*b == '\0')
					return ((char*)str);
				a++;
				b++;
			}
			b = (char*)to_find;
		}
		str++;
	}
	return (0);
}
