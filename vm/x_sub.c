/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_sub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:25:46 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/23 11:38:24 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		x_sub(t_player *player, unsigned char *arena)
{
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	arg3;

	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arena[player->pc] != 84)
		return ;
	arg1 = ft_get_n_bytes(arena, player->pc, 1);
	player->pc = (player->pc + 1) % MEM_SIZE;
	arg2 = ft_get_n_bytes(arena, player->pc, 1);
	player->pc = (player->pc + 1) % MEM_SIZE;
	arg3 = ft_get_n_bytes(arena, player->pc, 1);
	player->pc = (player->pc + 1) % MEM_SIZE;
	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arg1 < 1 || arg1 > REG_NUMBER || arg2 < 1 || arg2 > REG_NUMBER ||
		arg3 < 1 || arg3 > REG_NUMBER)
		return ;
	player->rgstrs[arg3 - 1] =
		player->rgstrs[arg1 - 1] - player->rgstrs[arg2 - 1];
	modify_carry(player, player->rgstrs[arg3 - 1]);
}
