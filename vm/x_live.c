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


static void	say_live(t_vm *vm, unsigned int name)
{
	int				i;

	i = 0;
	while (i < vm->players_count)
	{
		if ((unsigned int)vm->players[i].name == name)
		{
			vm->players[i].lives++;
			vm->players[i].last_live = vm->cycle;
		}
		i++;
	}
}

void		x_live(t_player *player, t_vm *vm)
{
	unsigned int	name;
	
	name = ft_get_n_bytes(vm->arena, player->pc, 4);
	player->pc = (player->pc + 1) % MEM_SIZE;
	player->pc = (player->pc + 1) % MEM_SIZE;
	say_live(vm, name);
}
