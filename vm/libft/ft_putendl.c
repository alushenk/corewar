/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:33:40 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/01 17:46:48 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl(char const *s)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
	write(1, "\n", 1);
}
