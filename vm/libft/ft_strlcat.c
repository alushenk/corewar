/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:18:29 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/05 15:25:24 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*td;
	char	*ts;
	size_t	len_cut_dst;
	size_t	len_addtodst;

	len_cut_dst = 0;
	td = dst;
	ts = (char*)src;
	while (len_cut_dst++ < size && *td != '\0')
		td++;
	len_cut_dst = ft_strlen(dst) - ft_strlen(td);
	len_addtodst = size - len_cut_dst;
	if (len_cut_dst == size)
		return (len_cut_dst + ft_strlen(src));
	while (*ts != '\0')
	{
		if (len_addtodst != 1)
		{
			*(td++) = *ts;
			len_addtodst--;
		}
		ts++;
	}
	*td = '\0';
	return (len_cut_dst + (ts - src));
}
