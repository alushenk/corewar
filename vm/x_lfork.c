/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:32:01 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/05 17:47:30 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			x_lfork(t_player *player, t_vm *vm)
{
	unsigned int	argv1;
	unsigned int	new_pc;
	t_player		*new_player;
	int				tmp;
	int             addr;

	addr = (int)player->pc;
	player->pc = (player->pc + 1) % MEM_SIZE;
	argv1 = ft_get_n_bytes(vm->arena, player->pc, 2);  // 2 или 4???
	new_pc = argv1;
	tmp = (int)new_pc;
	addr = addr + tmp;
	addr = addr % MEM_SIZE;
    if (addr < 0)
        addr += MEM_SIZE;
	new_pc = (unsigned int)addr;
	new_player = ft_create_new_player(player, new_pc);
	ft_add_new_player(vm, new_player);
}