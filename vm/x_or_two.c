/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_or.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:21:25 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/23 11:40:27 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ft_or_five(unsigned int *as, t_player *player,
			unsigned char *arena, int *tmp)
{
	if (arena[player->pc] == 244)
	{
		as[0] = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		*tmp = player->pc - 1 + (int)as[0];
		as[0] = ft_get_n_bytes(arena, ft_addr(*tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		as[1] = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		*tmp = player->pc - 3 + (int)as[1];
		as[1] = ft_get_n_bytes(arena, ft_addr(*tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	return (0);
}

void		ft_or_six(unsigned int *as, t_player *player)
{
	player->pc = (player->pc + 2) % MEM_SIZE;
	player->rgstrs[as[2] - 1] = as[0] | as[1];
	modify_carry(player, player->rgstrs[as[2] - 1]);
	free(as);
}
