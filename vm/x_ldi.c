/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ldi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:58:19 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/09 11:58:03 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			ft_ldi_one(unsigned int *as, t_player *player,
					unsigned char *arena)
{
	if (arena[player->pc] == 84)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		as[1] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[0] < 1 || as[0] > REG_NUMBER || as[1] < 1 || as[1] > REG_NUMBER)
			return (1);
		as[0] = player->rgstrs[as[0] - 1];
		as[1] = player->rgstrs[as[1] - 1];
	}
	else if (arena[player->pc] == 100)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[0] < 1 || as[0] > REG_NUMBER)
			return (1);
		as[0] = player->rgstrs[as[0] - 1];
		as[1] = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	return (0);
}

static int			ft_ldi_two(unsigned int *as, t_player *player,
					unsigned char *arena)
{
	if (arena[player->pc] == 148)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
		as[1] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[1] < 1 || as[1] > REG_NUMBER)
			return (1);
		as[1] = player->rgstrs[as[1] - 1];
	}
	else if (arena[player->pc] == 164)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
		as[1] = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	return (0);
}

static int			ft_ldi_three(unsigned int *as, t_player *player,
					unsigned char *arena, int *tmp)
{
	if (arena[player->pc] == 212)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 2);
		*tmp = player->pc - 1 + (int)as[0];
		as[0] = ft_get_n_bytes(arena, ft_addr(*tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		as[1] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[1] < 1 || as[1] > REG_NUMBER)
			return (1);
		as[1] = player->rgstrs[as[1] - 1];
	}
	else if (arena[player->pc] == 228)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 2);
		*tmp = player->pc - 1 + (int)as[0];
		as[0] = ft_get_n_bytes(arena, ft_addr(*tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		as[1] = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	return (0);
}

void				x_ldi(t_player *player, unsigned char *arena)
{
	unsigned int	*as;
	unsigned int	addr;
	int				tmp;
	int				flag;

	flag = 0;
	as = (unsigned int*)malloc(sizeof(unsigned int) * 3);
	addr = player->pc;
	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arena[player->pc] == 84 || arena[player->pc] == 100)
		flag = ft_ldi_one(as, player, arena);
	else if (arena[player->pc] == 148 || arena[player->pc] == 164)
		flag = ft_ldi_two(as, player, arena);
	else if (arena[player->pc] == 212 || arena[player->pc] == 228)
		flag = ft_ldi_three(as, player, arena, &tmp);
	if (flag == 1)
		return (free_ass(as));
	as[2] = ft_get_n_bytes(arena, player->pc, 1);
	if (as[2] < 1 || as[2] > REG_NUMBER)
		return (free_ass(as));
	player->pc = (player->pc + 2) % MEM_SIZE;
	addr = addr + ((int)as[0] + (int)as[1]) % IDX_MOD - 1;
	as[0] = ft_addr(addr);
	player->rgstrs[as[2] - 1] = ft_get_n_bytes(arena, as[0], 4);
	free(as);
}
