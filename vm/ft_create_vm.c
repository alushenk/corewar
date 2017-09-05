/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:23:01 by vrudenko          #+#    #+#             */
/*   Updated: 2017/09/05 13:12:06 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_player    ft_create_vm_player( int i, int num_players)
{
    t_player    vm_player;
    int         k;

    k = 1;

//    vm_player = (t_player*)malloc(sizeof(*vm_player));

    vm_player.name = -(i + 1);
    vm_player.rgstrs[0] = vm_player.name;
    while (k < REG_NUMBER)
    {
        vm_player.rgstrs[i] = 0;
        k++;
    }
//    printf("%d\n", i);
    vm_player.pc = (MEM_SIZE / num_players) * i;
    vm_player.alive = 1;
    vm_player.carry = 0;
    vm_player.cycle = 0;
    vm_player.lives = 0;
    vm_player.last_live = 0;


    return (vm_player);
}

static t_player    *ft_create_vm_players_array(t_players **players_array, int num_players)
{
    t_player    *players_vm_array;
    int         i;

    i = 0;

    players_vm_array = (t_player*)malloc(sizeof(t_player) * num_players + 1);
    players_array[num_players] = 0;

    while (i < num_players)
    {
        players_vm_array[i] = ft_create_vm_player(i, num_players);
        i++;
    }

    return (players_vm_array);
}

t_vm    *ft_create_vm(unsigned char *arena, t_players **players_array, int argc)
{
    t_vm    *vm;

    vm = (t_vm*)malloc(sizeof(*vm));

    vm->arena = arena;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->cycle = 0;
    vm->current_cycle = 0;
    vm->max_checks = MAX_CHECKS;
    vm->players = ft_create_vm_players_array(players_array, argc - 1);
    vm->players_count = argc - 1;


    return (vm);
}
