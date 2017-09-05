/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:25:11 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/03 14:36:36 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fresh;
	char	*temp;

	if (!(s) || !f)
		return (NULL);
	if ((fresh = (char*)malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	temp = (char*)s;
	while (s[i] != '\0')
	{
		fresh[i] = (*f)(temp[i]);
		i++;
	}
	fresh[i] = '\0';
	return (&fresh[0]);
}
