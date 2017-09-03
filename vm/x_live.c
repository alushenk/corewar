/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:32:01 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/03 15:38:47 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	say_live(t_vm *vm, unsigned int name, int cycle)
{
	int				i;

	i = 0;
	while (vm->players[i])
	{
		if ((unsigned int)vm->players[i]->name == name)
		{
			vm->players[i]->lives++;
			vm->players[i]->last_live = cycle;
		}
		i++;
	}
}

void		x_live(t_player *palyer, char **arena, t_vm *vm, int cycle)
{
	unsigned int	*name;
	
	name = get_4_bytes(arena, player->pc);//add!
	player->pc = (player->pc + 1) % MEM_SIZE;
	player->pc = (player->pc + 1) % MEM_SIZE;
	say_live(vm, name);
}
