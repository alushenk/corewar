/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:11:21 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/05 17:10:50 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"


void		x_ld(t_player *player, unsigned char *arena)
{
	unsigned int	arg1;
	unsigned int	arg2;

	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arena[player->pc] == 144)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 4) % IDX_MOD;
		player->pc = (player->pc + 4) % MEM_SIZE;
	}
	else if (arena[player->pc] == 208)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 2);
		arg1 = ft_get_n_bytes(arena, (player->pc + arg1) % MEM_SIZE, 4)
			% IDX_MOD;
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	else
		return ;
	arg2 = ft_get_n_bytes(arena, player->pc, 1);
	player->pc = (player->pc + 1) % MEM_SIZE;
	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arg2 > 0 && arg2 < REG_NUMBER + 1)
		player->rgstrs[arg2 - 1] = arg1;
	player->carry = 1;
}