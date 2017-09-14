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

static int	no_live_payers(t_vm *vm)
{
	int		i;

	i = 0;
	while(i < vm->players_count)
	{
		if (vm->players[i].alive)
			return (0);
		i++;
	}
	return (1);
}

static void	update_alive(t_vm *vm)
{
	int		i;

	i = 0;
	while(i < vm->players_count)
	{
		if (vm->players[i].alive)
		{
			if (vm->players[i].last_live < (vm->current_cycle - vm->cycle_to_die))
				vm->players[i].alive = 0;
		}
		i++;
	}
}

static int	nbr_live(t_vm *vm)
{
	int		i;
	int		nbr_live;

	i = 0;
	nbr_live = 0;
	while(i < vm->players_count)
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
	{//
		printf("\n\nno live players\n\n");//test
		return (1);
	}//
	if (nbr_live(vm) >= NBR_LIVE || !vm->max_checks)
	{
		vm->max_checks = MAX_CHECKS;
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->current_cycle = 0;
		clear_players_lives(vm);
		if (vm->cycle_to_die > 0)
			return (0);
		else
		{//
			printf("\n\nno cycle to die\n\n");//test
			return (1);
		}//
	}
	vm->max_checks--;
	return (0);
}

void		play(t_vm *vm, int fd)
{
	int		i;
//	char	c;

	//int Z = 1270;//test
    //&& vm->cycle < Z + 1
	while (!(end(vm)))
	{
//		while(1)
//		{
//			c = getchar();
//			if (c == 's' || c == ']')
//			{
            if (vm->cycle % 100 == 0)
			    printf("\nCYCLE: %d\n\n", vm->cycle);//test
				//	printf("\nCURRENT CYCLE: %d\n\n", vm->current_cycle);//test
				//printf("\nCYCLE TO DIE: %d\n\n", vm->cycle_to_die);//test

			write_log(fd, vm);
			//fd = 1;

			// if (vm->cycle > Z - 5) //test
			// ft_print_map(vm);
				i = 0;
				while (i < vm->players_count)
				{
					vm->players[i].cycle++;
					if (enough_cycle(vm->players[i].cycle, vm->arena[vm->players[i].pc]))
					{
						move(&(vm->players[i]), vm);
						vm->players[i].cycle = 0;
					}
					//testtttttttttttttt

/*
					int		r = 0;
					while (r < 16)
					{
						printf("ARG%d: %u\n", r + 1, vm->players[i].rgstrs[r]);//TEST
						r++;
					}

*/
					//testttttttttttttttttttt
					i++;
				}
				vm->cycle++;
				vm->current_cycle++;
//			}
				//if (c == 'q')
				//return ;
				//}
			}
}
