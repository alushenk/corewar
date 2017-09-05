/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 20:11:42 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/05 14:23:14 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_f, size_t len)
{
	char	*a;
	char	*b;
	size_t	l;

	l = len;
	b = (char*)to_f;
	if (*b == '\0')
		return ((char*)str);
	while (*(char*)str != '\0' && len != 0)
	{
		if (*(char*)str == *b)
		{
			l = 0;
			a = (char*)str;
			while ((*(a + l) == *(b + l) || *(b + l) == '\0') && l++ <= len)
			{
				if (*(b + l - 1) == '\0')
					return ((char*)str);
			}
			b = (char*)to_f;
		}
		str++;
		len--;
	}
	return (NULL);
}
