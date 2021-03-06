/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:48:39 by opanchen          #+#    #+#             */
/*   Updated: 2016/12/05 17:36:14 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *ptr1;

	ptr1 = s1;
	while (*ptr1 != '\0')
	{
		ptr1++;
	}
	while (*s2 != '\0')
	{
		*ptr1 = *s2;
		ptr1++;
		s2++;
	}
	*ptr1 = '\0';
	return (s1);
}
