/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:44:41 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/04 13:06:56 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	put_value(t_player *palyer, char *arena, unsigned int arg1,
					  unsigned int arg2)
{
	int		addr;

	addr = pc + (player->rgstrs[arg1] % IDX_MOD);
	addr = addr % MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	// put velue to ddr
}

void		x_st(t_player *palyer, char *arena)
{
	unsigned int    arg1;
    unsigned int    arg2;

	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arena[player->pc] = 112)
    {
        arg2 = get_2_bytes(arena, player->pc) % IDX_MOD;
        player->pc = (player->pc + 2) % MEM_SIZE;
    }
    else if (arena[player->pc] = 80)
    {
        arg2 = get_1_byte(arena, player->pc) % IDX_MOD;
        player->pc = (player->pc + 1) % MEM_SIZE;
    }
    else
        return ;
	arg1 = get_1_byte(arena, player->pc);
	if (arg1 < REG_NUMBER)
		put_value(player, arena, arg1);
    player->pc = (player->pc + 1) % MEM_SIZE;
    player->pc = (player->pc + 1) % MEM_SIZE;
}
/*
**
** get_bytes - может возвращать минусовые значения
**
**
**
**
**
**
**
**
*/
