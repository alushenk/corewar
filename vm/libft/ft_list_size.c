/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:50:26 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/02 21:33:07 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*list;

	count = 0;
	list = begin_list;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}
