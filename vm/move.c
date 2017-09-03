/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 13:00:21 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/03 15:09:59 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		move(t_player *palyer, char **arena, t_vm *vm, int cycle)
{
	if (*(arena[player->pc]) == 1)
		x_live(player, arena, vm, cycle);
	else  if (*(arena[player->pc]) == 2)
		x_ld(player, arena, vm);
	else  if (*(arena[player->pc]) == 3)
        x_st(player, arena, vm);
	else  if (*(arena[player->pc]) == 4)
        x_add(player, arena, vm);
	else  if (*(arena[player->pc]) == 5)
        x_sub(player, arena, vm);
	else  if (*(arena[player->pc]) == 6)
        x_and(player, arena, vm);
	else  if (*(arena[player->pc]) == 7)
        x_or(player, arena, vm);
	else  if (*(arena[player->pc]) == 8)
        x_xor(player, arena, vm);
	else  if (*(arena[player->pc]) == 9)
        x_zjmp(player, arena, vm);
	else  if (*(arena[player->pc]) == 10)
        x_ldi(player, arena, vm);
	else  if (*(arena[player->pc]) == 11)
        x_sti(player, arena, vm);
	else  if (*(arena[player->pc]) == 12)
        x_fork(player, arena, vm);
	else  if (*(arena[player->pc]) == 13)
        x_lld(player, arena, vm);
	else  if (*(arena[player->pc]) == 14)
        x_lldi(player, arena, vm);
	else  if (*(arena[player->pc]) == 15)
        x_lfork(player, arena, vm);
	else  if (*(arena[player->pc]) == 16)
        x_aff(player, arena, vm);
	else
		player->pc = (player->pc + 1) % MEM_SIZE;
}
