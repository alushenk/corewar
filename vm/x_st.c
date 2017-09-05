/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:44:41 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/05 11:54:42 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	put_value_from_reg(t_player *player, char *arena,
						unsigned int arg1, unsigned int arg2)
{
	int				addr;
	unsigned int	value;

	addr = pc + (player->rgstrs[arg1 - 1] % IDX_MOD);
	addr = addr % MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	value = player->rgstrs[arg2 - 1];
	arena[addr] = (value & 0x000000FF);
	arena[(addr + 1) % MEM_SIZE] = (value & 0x0000FF00) >> 8;
	arena[(addr + 2) % MEM_SIZE] = (value & 0x00FF0000) >> 16;
	arena[(addr + 3) % MEM_SIZE] = (value & 0xFF000000) >> 24;
}

static void	put_value_from_ind(t_player *palyer, char *arena,
						unsigned int arg1, unsigned int arg2)
{
	int				addr;

	addr = pc + (player->rgstrs[arg1 - 1] % IDX_MOD);
	addr = addr % MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	arena[addr] = (arg2 & 0x000000FF);
	arena[(addr + 1) % MEM_SIZE] = (arg2 & 0x0000FF00) >> 8;
}

void		x_st(t_player *palyer, char *arena)
{
	unsigned int	arg1;
	unsigned int	arg2;

	player->pc = (player->pc + 1) % MEM_SIZE;
	arg1 = ft_get_n_bytes(arena, player->pc, 1);
	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arg1 < 1 || arg1 > REG_NUMBER)
		return ;
	if (arena[player->pc] = 112)
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		player->pc = (player->pc + 2) % MEM_SIZE;
		put_value_from_ind(player, arena, arg1, arg2);
	}
	else if (arena[player->pc] = 80)
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 1) % IDX_MOD;
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg2 > 0 && arg2 < REG_NUMBER + 1)
			put_value_from_reg(player, arena, arg1, arg2);
	}
	else
		return ;
	player->pc = (player->pc + 1) % MEM_SIZE;
}
