/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_and.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:27:31 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/07 15:42:02 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ft_and_five(unsigned int *as, t_player *player,
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

void		ft_and_six(unsigned int *as, t_player *player)
{
	player->pc = (player->pc + 1) % MEM_SIZE;
	player->pc = (player->pc + 1) % MEM_SIZE;
	player->rgstrs[as[2] - 1] = as[0] & as[1];
	player->carry = 1;
}
