/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_sti.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:30:27 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/09 14:26:38 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			ft_x_sti_one(unsigned int *as, t_player *player,
					unsigned char *arena)
{
	if (arena[player->pc - 1] == 84)
	{
		as[1] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[1] < 1 || as[1] > REG_NUMBER)
			return (1);
		as[1] = player->rgstrs[as[1] - 1];
		as[2] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[2] < 1 || as[2] > REG_NUMBER)
			return (1);
		as[2] = player->rgstrs[as[2] - 1];
	}
	else if (arena[player->pc - 1] == 88)
	{
		as[1] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[1] < 1 || as[1] > REG_NUMBER)
			return (1);
		as[1] = player->rgstrs[as[1] - 1];
		as[2] = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	return (0);
}

static int			ft_x_sti_two(unsigned int *as, t_player *player,
					unsigned char *arena)
{
	if (arena[player->pc - 1] == 100)
	{
		as[1] = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
		as[2] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[2] < 1 || as[2] > REG_NUMBER)
			return (1);
		as[2] = player->rgstrs[as[2] - 1];
	}
	else if (arena[player->pc - 1] == 104)
	{
		as[1] = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
		as[2] = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	return (0);
}

static int			ft_x_sti_three(unsigned int *as, t_player *player,
					unsigned char *arena, int *tmp)
{
	if (arena[player->pc - 1] == 116)
	{
		as[1] = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		*tmp = player->pc - 2 + (int)as[1];
		as[1] = ft_get_n_bytes(arena, ft_addr(*tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		as[2] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[2] < 1 || as[2] > REG_NUMBER)
			return (1);
		as[2] = player->rgstrs[as[2] - 1];
	}
	else if (arena[player->pc - 1] == 120)
	{
		as[1] = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		*tmp = player->pc - 2 + (int)as[1];
		as[1] = ft_get_n_bytes(arena, ft_addr(*tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		as[2] = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	return (0);
}

static void			ft_x_sti_four(unsigned int *as, unsigned char *arena,
				int *tmp, unsigned int *addr)
{
	*tmp = ((int)as[1] + (int)as[2]) % IDX_MOD;
	as[1] = ft_addr(*tmp + *addr);
	arena[(as[1] + 3) % MEM_SIZE] = (as[0] & 0x000000FF);
	arena[(as[1] + 2) % MEM_SIZE] = (as[0] & 0x0000FF00) >> 8;
	arena[(as[1] + 1) % MEM_SIZE] = (as[0] & 0x00FF0000) >> 16;
	arena[(as[1] + 0) % MEM_SIZE] = (as[0] & 0xFF000000) >> 24;
}

void				x_sti(t_player *player, unsigned char *arena, int flag)
{
	unsigned int	*as;
	unsigned int	addr;
	int				tmp;

	as = (unsigned int*)malloc(sizeof(unsigned int) * 3);
	addr = player->pc;
	player->pc = (player->pc + 1) % MEM_SIZE;
	as[0] = ft_get_n_bytes(arena, player->pc, 1);
	if (as[0] < 1 || as[0] > REG_NUMBER)
		return ;
	as[0] = player->rgstrs[as[0] - 1];
	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arena[player->pc] == 84 || arena[player->pc] == 88)
		flag = ft_x_sti_one(as, player, arena);
	else if (arena[player->pc - 1] == 100 || arena[player->pc - 1] == 104)
		flag = ft_x_sti_two(as, player, arena);
	else if (arena[player->pc - 1] == 116 || arena[player->pc - 1] == 120)
		flag = ft_x_sti_three(as, player, arena, &tmp);
	if (flag == 1)
		return ;
	player->pc = (player->pc + 1) % MEM_SIZE;
	ft_x_sti_four(as, arena, &tmp, &addr);
	player->is_change = 1;
	player->addr_of_change = as[1];
	free(as);
}
