/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:07:30 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/09 14:13:27 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			no_live_payers(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < vm->players_count)
	{
		if (vm->players[i].alive)
			return (0);
		i++;
	}
	return (1);
}

void		update_alive(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < vm->players_count)
	{
		if (vm->players[i].alive)
		{
			if (vm->players[i].last_live <
				(vm->current_cycle - vm->cycle_to_die))
				vm->players[i].alive = 0;
		}
		i++;
	}
}
