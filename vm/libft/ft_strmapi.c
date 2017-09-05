/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:12:35 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/01 17:31:46 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	char			*tmp;
	unsigned int	i;
	int				len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if ((fresh = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	tmp = (char*)s;
	while (tmp[i] != '\0')
	{
		fresh[i] = f(i, tmp[i]);
		i++;
	}
	fresh[len] = '\0';
	return (fresh);
}
