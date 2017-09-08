/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_lfork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:46:25 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/08 14:35:11 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			x_lfork(t_player *player, t_vm *vm)
{
	unsigned int	arg1;
	unsigned int	new_pc;
	t_player		*new_player;
	int				tmp;
	int             addr;

	addr = (int)player->pc;
	arg1 = ft_get_n_bytes(vm->arena, player->pc, 2);
	player->pc = (player->pc + 2) % MEM_SIZE;
	tmp = (int)arg1;
	addr = addr + tmp;
	addr = addr % MEM_SIZE;
    if (addr < 0)
        addr += MEM_SIZE;
	new_pc = (unsigned int)addr;
	new_player = ft_create_new_player(player, new_pc);
	ft_add_new_player(vm, new_player);	
	player->pc = (player->pc + 1) % MEM_SIZE;
}
