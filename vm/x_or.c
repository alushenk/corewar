/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_or.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:21:25 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/07 15:47:43 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		ft_or_one(unsigned int *as, t_player *player,
				unsigned char *arena, int *tmp)
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
	else if (arena[player->pc] == 116)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[0] < 1 || as[0] > REG_NUMBER)
			return (1);
		as[0] = player->rgstrs[as[0] - 1];
		as[1] = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		*tmp = player->pc - 2 + (int)as[1];
		as[1] = ft_get_n_bytes(arena, ft_addr(*tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	return (0);
}

static int		ft_or_two(unsigned int *as, t_player *player,
				unsigned char *arena)
{
	if (arena[player->pc] == 100)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[0] < 1 || as[0] > REG_NUMBER)
			return (1);
		as[0] = player->rgstrs[as[0] - 1];
		as[1] = ft_get_n_bytes(arena, player->pc, 4);
		player->pc = (player->pc + 4) % MEM_SIZE;
	}
	else if (arena[player->pc] == 148)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 4);
		player->pc = (player->pc + 4) % MEM_SIZE;
		as[1] = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (as[1] < 1 || as[1] > REG_NUMBER)
			return (1);
		as[1] = player->rgstrs[as[1] - 1];
	}
	return (0);
}

static int		ft_or_three(unsigned int *as, t_player *player,
				unsigned char *arena, int *tmp)
{
	if (arena[player->pc] == 164)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 4);
		player->pc = (player->pc + 4) % MEM_SIZE;
		as[1] = ft_get_n_bytes(arena, player->pc, 4);
		player->pc = (player->pc + 4) % MEM_SIZE;
	}
	else if (arena[player->pc] == 180)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 4);
		player->pc = (player->pc + 4) % MEM_SIZE;
		as[1] = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		*tmp = player->pc - 5 + (int)as[1];
		as[1] = ft_get_n_bytes(arena, ft_addr(*tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	return (0);
}

static int		ft_or_four(unsigned int *as, t_player *player,
				unsigned char *arena, int *tmp)
{
	if (arena[player->pc] == 212)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
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
		as[0] = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		*tmp = player->pc - 1 + (int)as[0];
		as[0] = ft_get_n_bytes(arena, ft_addr(*tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		as[1] = ft_get_n_bytes(arena, player->pc, 4);
		player->pc = (player->pc + 4) % MEM_SIZE;
	}
	return (0);
}

void			x_or(t_player *player, unsigned char *arena)
{
	unsigned int	*as;
	int				tmp;
	int				flag;

	flag = 0;
	player->pc = (player->pc + 1) % MEM_SIZE;
	as = (unsigned int*)malloc(sizeof(unsigned int) * 3);
	if (arena[player->pc] == 84 || arena[player->pc] == 116)
		flag = ft_or_one(as, player, arena, &tmp);
	else if (arena[player->pc] == 100 || arena[player->pc] == 148)
		flag = ft_or_two(as, player, arena);
	else if (arena[player->pc] == 164 || arena[player->pc] == 180)
		flag = ft_or_three(as, player, arena, &tmp);
	else if (arena[player->pc] == 212 || arena[player->pc] == 228)
		flag = ft_or_four(as, player, arena, &tmp);
	else if (arena[player->pc] == 212 || arena[player->pc] == 228)
		flag = ft_or_five(as, player, arena, &tmp);
	if (flag == 1)
		return ;
	as[2] = ft_get_n_bytes(arena, player->pc, 1);
	if (as[2] < 1 || as[2] > REG_NUMBER)
		return ;
	ft_or_six(as, player);
}
