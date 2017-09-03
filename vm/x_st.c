/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:44:41 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/03 16:25:44 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		x_st(t_player *palyer, char **arena)
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
        arg2 = get_1_byte1(arena, player->pc) % IDX_MOD;
        player->pc = (player->pc + 1) % MEM_SIZE;
    }
    else
        return ;
	arg1 = get_1_byte(arena, player->pc);
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
