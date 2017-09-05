/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrslplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:15:18 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/05 15:10:20 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lststrsplit(char const *s, char c)
{
	char	**tmp;
	t_list	*list;

	tmp = ft_strsplit(s, c);
	if (!tmp || !(*tmp))
		return (0);
	list = ft_lstnew(*tmp, ft_strlen(*tmp));
	tmp++;
	while (*tmp != 0)
	{
		ft_lstpushback(list, *tmp, ft_strlen(*tmp));
		tmp++;
	}
	return (list);
}
