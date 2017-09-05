/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:40:15 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/03 15:40:09 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	char	*tmp;

	tmp = (char*)content;
	list = NULL;
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(list->content = (void*)malloc(content_size)))
		return (NULL);
	if (!tmp)
	{
		list->content = NULL;
		list->content_size = 0;
		return (list);
	}
	list->content = ft_memcpy(list->content, (void *)content, content_size);
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
