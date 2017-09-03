/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:07:30 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/03 12:59:47 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	no_live_payers(t_player **players, int players_count)
{
	int		i;

	i = 0;
	while(i < players_count)
	{
		if ((*playrs[i])->alive)
			return (0);
		i++;
	}
	return (1);
}

static void	update_alive(t_player **players, t_vm *vm, int cycle)
{
	int		i;

	i = 0;
	while(i < players_count)
	{
		if ((*playrs[i])->alive)
		{
			if ((*playrs[i])->last_live < (cycle - vm->cycle_to_die))
				(*playrs[i])->alive = 0;
		}
		i++;
	}
}

static int	nbr_live(t_player **players, int players_count)
{
	int		i;
	int		nbr_live;

	i = 0;
	nbr_live = 0;
	while(i < players_count)
	{
		nbr_live += (*playrs[i])->lives;
		i++;
	}
	return (nbr_live);
}

static int	end(t_vm *vm, t_player **players, int cycle)
{
	if (vm->cycle_to_die < vm->cycle)
		return (0);
	update_alive(palyers, vm, cycle);
	if (no_live_payers(players, vm->players_count))
		return (1);
	if (nbr_live(palyers, vm->players_count) >= NBR_LIVE || !vm->max_checks)
	{
		vm->max_checks == MAX_CHECKS;
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->cycle = 0;
		if (vm->cycle_to_die > 0)
			return (0);
		else
			return (1);
	}
	vm->max_checks--;
	return (0);
}

void		play(char *arena, t_player *players)
{
	int		cycle;
	int		i;
	t_vm	vm;

	vm = create_vm(players);//add!
	cycle = 0;
	while (!end(&vm, &players, cycle))
	{
		i = 0;
		while (i < vm.players_count)
		{
			if (!(players[i].cycle))
				move(&players[i], &arena, &vm);
			i++;
		}
		cycle++;
	}
}
