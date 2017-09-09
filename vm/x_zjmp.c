/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:37:03 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/09 14:11:05 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		x_zjmp(t_player *player, unsigned char *arena)
{
	unsigned int	arg;
	int				tmp1;
	int				tmp2;
	int             addr;

	if (!player->carry)
	{
		player->pc = (player->pc + 3) % MEM_SIZE;
		return ;
	}
	arg = ft_get_n_bytes(arena, player->pc, 2);
	tmp1 = (int)arg;
	tmp2 = (int)player->pc;
	addr = tmp1 + tmp2;
	addr = addr % MEM_SIZE;
    if (addr < 0)
        addr += MEM_SIZE;
	arg = (unsigned int)addr;
	player->pc = arg;
}
