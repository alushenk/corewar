/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:23:50 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/03 17:25:06 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list *begin_list, void *data, size_t c_s)
{
	t_list	*list;
	t_list	*end;

	end = ft_lstnew(data, c_s);
	if (begin_list)
	{
		list = begin_list;
		while (list->next)
		{
			list = list->next;
		}
		list->next = end;
	}
	else
	{
		begin_list = end;
	}
}
