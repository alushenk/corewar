/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 13:00:21 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/23 11:44:56 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	move_two(t_player *player, t_vm *vm)
{
	if (vm->arena[player->pc] == 9)
		x_zjmp(player, vm->arena);
	else if (vm->arena[player->pc] == 10)
		x_ldi(player, vm->arena);
	else if (vm->arena[player->pc] == 11)
		x_sti(player, vm->arena, 1);
	else if (vm->arena[player->pc] == 12)
		x_fork(player, vm);
	else if (vm->arena[player->pc] == 13)
		x_lld(player, vm->arena);
	else if (vm->arena[player->pc] == 14)
		x_lldi(player, vm->arena, 0);
	else if (vm->arena[player->pc] == 15)
		x_lfork(player, vm);
	else if (vm->arena[player->pc] == 16)
		x_aff(player, vm->arena);
}

void		move(t_player *player, t_vm *vm)
{
	if (vm->arena[player->pc] == 1)
		x_live(player, vm);
	else if (vm->arena[player->pc] == 2)
		x_ld(player, vm->arena);
	else if (vm->arena[player->pc] == 3)
		x_st(player, vm->arena);
	else if (vm->arena[player->pc] == 4)
		x_add(player, vm->arena);
	else if (vm->arena[player->pc] == 5)
		x_sub(player, vm->arena);
	else if (vm->arena[player->pc] == 6)
		x_and(player, vm->arena);
	else if (vm->arena[player->pc] == 7)
		x_or(player, vm->arena);
	else if (vm->arena[player->pc] == 8)
		x_xor(player, vm->arena);
	else if (vm->arena[player->pc] >= 9
	&& vm->arena[player->pc] <= 16)
		move_two(player, vm);
	else
		player->pc = (player->pc + 1) % MEM_SIZE;
}
