/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:07:03 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/07 13:08:49 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	ft_addr(int tmp)
{
	unsigned int addr;

	tmp = tmp % MEM_SIZE;
	if (tmp < 0)
		tmp += MEM_SIZE;
	addr = (unsigned int)tmp;

	return (addr);
}
