/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_or.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:21:25 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/07 13:21:49 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		x_and(t_player *player, unsigned char *arena)
{
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	arg3;
	int				tmp;

	player->pc = (player->pc + 1) % MEM_SIZE;
    if (arena[player->pc] == 84)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		arg2 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg1 < 1 || arg1 > REG_NUMBER || arg2 < 1 || arg2 > REG_NUMBER)
			return ;
		arg1 = player->rgstrs[arg1 - 1];
		arg2 = player->rgstrs[arg2 - 1];
	}
	else if (arena[player->pc] == 116)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 1);
        player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg1 < 1 || arg1 > REG_NUMBER)
            return ;
		arg1 = player->rgstrs[arg1 - 1];
		arg2 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		tmp = player->pc - 2 + (int)arg2;
		arg2 = ft_get_n_bytes(arena, ft_addr(tmp), 4);
        player->pc = (player->pc + 2) % MEM_SIZE;
	}
	else if (arena[player->pc] == 100)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 1);
        player->pc = (player->pc + 1) % MEM_SIZE;
        if (arg1 < 1 || arg1 > REG_NUMBER)
            return ;
        arg1 = player->rgstrs[arg1 - 1];
        arg2 = ft_get_n_bytes(arena, player->pc, 4);
        player->pc = (player->pc + 4) % MEM_SIZE;
	}
	else if (arena[player->pc] == 148)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 4);
		player->pc = (player->pc + 4) % MEM_SIZE;
        arg2 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg2 < 1 || arg2 > REG_NUMBER)
            return ;
		arg2 = player->rgstrs[arg2 - 1];
	}
	else if (arena[player->pc] == 164)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 4);
        player->pc = (player->pc + 4) % MEM_SIZE;
		arg2 = ft_get_n_bytes(arena, player->pc, 4);
        player->pc = (player->pc + 4) % MEM_SIZE;
	}
	else if (arena[player->pc] == 180)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 4);
        player->pc = (player->pc + 4) % MEM_SIZE;
		arg2 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		tmp = player->pc - 5 + (int)arg2;
		arg2 = ft_get_n_bytes(arena, ft_addr(tmp), 4);
        player->pc = (player->pc + 2) % MEM_SIZE;
	}
	else if (arena[player->pc] == 212)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		tmp = player->pc - 1 + (int)arg1;
		arg1 = ft_get_n_bytes(arena, ft_addr(tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		arg2 = ft_get_n_bytes(arena, player->pc, 1);
        player->pc = (player->pc + 1) % MEM_SIZE;
        if (arg2 < 1 || arg2 > REG_NUMBER)
            return ;
		arg2 = player->rgstrs[arg2 - 1];
	}
	else if (arena[player->pc] == 228)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		tmp = player->pc - 1 + (int)arg1;
		arg1 = ft_get_n_bytes(arena, ft_addr(tmp), 4);
        player->pc = (player->pc + 2) % MEM_SIZE;
		arg2 = ft_get_n_bytes(arena, player->pc, 4);
        player->pc = (player->pc + 4) % MEM_SIZE;
	}
	else if (arena[player->pc] == 244)
	{
		arg1 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		tmp = player->pc - 1 + (int)arg1;
		arg1 = ft_get_n_bytes(arena, ft_addr(tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		arg2 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		tmp = player->pc - 3 + (int)arg2;
		arg2 = ft_get_n_bytes(arena, ft_addr(tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}

	arg3 = ft_get_n_bytes(arena, player->pc, 1);
	if (arg3 < 1 || arg3 > REG_NUMBER)
		return ;
	player->pc = (player->pc + 1) % MEM_SIZE;
	player->rgstrs[arg3 - 1] = arg1 | arg2;
	player->carry = 1;
}
