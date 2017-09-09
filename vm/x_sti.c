/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_sti.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:30:27 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/09 13:03:09 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void		x_sti(t_player *player, unsigned char *arena)
{
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	arg3;
	unsigned int	addr;
	int				tmp;

	addr = player->pc;
	player->pc = (player->pc + 1) % MEM_SIZE;
	arg1 = ft_get_n_bytes(arena, player->pc, 1);
	if (arg1 < 1 || arg1 > REG_NUMBER)
		return ;
	arg1 = player->rgstrs[arg1 - 1];
	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arena[player->pc - 1] == 84) // T_REG | T_REG | T_REG
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg2 < 1 || arg2 > REG_NUMBER)
			return ;
		arg2 = player->rgstrs[arg2 - 1];
		arg3 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg3 < 1 || arg3 > REG_NUMBER)
			return ;
		arg3 = player->rgstrs[arg3 - 1];
	}
	else if (arena[player->pc - 1] == 88) // T_REG | T_REG | T_DIR
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg2 < 1 || arg2 > REG_NUMBER)
			return ;
		arg2 = player->rgstrs[arg2 - 1];
		arg3 = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	else if (arena[player->pc - 1] == 100) // T_REG | T_DIR | T_REG
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 1) % MEM_SIZE;
		arg3 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 2) % MEM_SIZE;
		if (arg3 < 1 || arg3 > REG_NUMBER)
			return ;
		arg3 = player->rgstrs[arg3 - 1];
	}
	else if (arena[player->pc - 1] == 104) // T_REG | T_DIR | T_DIR
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
		arg3 = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	else if (arena[player->pc - 1] == 116) // T_REG | T_IND | T_REG
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
        tmp = player->pc - 2 + (int)arg2;
        arg2 = ft_get_n_bytes(arena, ft_addr(tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		arg3 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg3 < 1 || arg3 > REG_NUMBER)
			return ;
		arg3 = player->rgstrs[arg3 - 1];
	}
	else if (arena[player->pc - 1] == 120) // T_REG | T_IND | T_DIR
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
        tmp = player->pc - 2 + (int)arg2;
        arg2 = ft_get_n_bytes(arena, ft_addr(tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		arg3 = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	else 
		return ;
	player->pc = (player->pc + 1) % MEM_SIZE;
	tmp = ((int)arg2 + (int)arg3) % IDX_MOD;
	arg2 = ft_addr(tmp + addr);
	arena[(arg2 + 3) % MEM_SIZE] = (arg1 & 0x000000FF);
    arena[(arg2 + 2) % MEM_SIZE] = (arg1 & 0x0000FF00) >> 8;
    arena[(arg2 + 1) % MEM_SIZE] = (arg1 & 0x00FF0000) >> 16;
    arena[(arg2 + 0) % MEM_SIZE] = (arg1 & 0xFF000000) >> 24;
}
