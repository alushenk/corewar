/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lush <lush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:23:01 by vrudenko          #+#    #+#             */
/*   Updated: 2017/09/15 00:19:46 by lush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	char	*t;

	i = 0;
	t = dest;
	while (i < len)
	{
		// if (src[i] == '\0' || flag == 1)
		// {
			// t[i] = '\0';
			// flag = 1;
		// }
		// if (flag == 0)
			t[i] = src[i];
		i++;
	}
	return (dest);
}
