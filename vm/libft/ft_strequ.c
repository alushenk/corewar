/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lush <lush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:15:27 by vrudenko          #+#    #+#             */
/*   Updated: 2017/09/15 00:18:50 by lush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{

	if (!s1 || !s2)
		return (0);

	if (ft_strcmp((char*)s1, (char*)s2) == 0)
		return (1);
	return (0);
}
