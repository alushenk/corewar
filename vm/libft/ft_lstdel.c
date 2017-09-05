/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:15:20 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/03 15:37:26 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	temp = *alst;
	while (*alst)
	{
		temp = *alst;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = (temp)->next;
	}
}
