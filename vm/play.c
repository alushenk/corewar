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

static int	nbr_live(t_vm *vm)
{
	int		i;
	int		nbr_live;

	i = 0;
	nbr_live = 0;
	while (i < vm->players_count)
	{
		nbr_live += vm->players[i].lives;
		i++;
	}
	return (nbr_live);
}

static void	clear_players_lives(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < vm->players_count)
	{
		vm->players[i].lives = 0;
		i++;
	}
}

static int	end(t_vm *vm)
{
	if (vm->cycle_to_die > vm->current_cycle)
		return (0);
	update_alive(vm);
	if (no_live_payers(vm))
	{
		return (1);
	}
	if (nbr_live(vm) >= NBR_LIVE || !vm->max_checks)
	{
		vm->max_checks = MAX_CHECKS;
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->current_cycle = 0;
		clear_players_lives(vm);
		if (vm->cycle_to_die > 0)
			return (0);
		else
		{
			return (1);
		}
	}
	vm->max_checks--;
	return (0);
}

void		play(t_vm *vm, FILE *fd)
{
	int				norm[4];
	char			*load_line;

	load_line = ft_create_load_line();
	norm[1] = ft_math_cycles(&norm[3], &norm[2]);
	while (!(end(vm)))
	{
		ft_draw_loading(&norm[3], &norm[2], load_line, &norm[1]);
		write_log(fd, vm);
		norm[0] = 0;
		while (norm[0] < vm->players_count)
		{
			vm->players[norm[0]].cycle++;
			if (enough_cycle(vm->players[norm[0]].cycle,
				vm->arena[vm->players[norm[0]].pc]))
			{
				move(&(vm->players[norm[0]]), vm);
				vm->players[norm[0]].cycle = 0;
			}
			norm[0]++;
		}
		vm->cycle++;
		vm->current_cycle++;
	}
	ft_draw_loaded(load_line);
}
