/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:11:21 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/04 12:53:13 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		x_ld(t_player *palyer, char *arena)
{
	unsigned int	arg1;
	unsigned int	arg2;

	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arena[player->pc] = 144)
	{
		arg1 = get_4_bytes(arena, player->pc) % IDX_MOD;
		player->pc = (player->pc + 4) % MEM_SIZE;
	}
	else if (arena[player->pc] = 208)
	{
		arg1 = get_2_bytes(arena, player->pc) % IDX_MOD;
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	else
		return ;
	arg2 = get_1_byte(arena, player->pc);
	player->pc = (player->pc + 1) % MEM_SIZE;
	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arg2 < REG_NUMBER)
		player->rgstr[arg2] = arg1;
	if (arg1 == 0)
		player->carry = 1;
}
