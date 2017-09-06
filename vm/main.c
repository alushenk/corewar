/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 12:30:36 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/05 13:30:29 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"


void ft_error(char *error_name)
{
	printf("%s\n", error_name);
	exit(0);
}


unsigned  char	*fill_arena(unsigned char *arena, t_players **players, int argc)
{
    int     delta;
    int     i;
    unsigned int     k;

    i = 0;

    delta = MEM_SIZE / (argc - 1);

    printf("delta = %d\n", delta);
    while (i < argc - 1)
    {
        k = 0;
        while (k < players[i]->size)
        {
            arena[(i * delta) + k] = players[i]->code[k];
            k++;
        }
        i++;
    }
    return (arena);
}


unsigned char	*create_arena(void)
{
    unsigned char	*arena;
    int		i;

    i = 0;
    if (!(arena = (unsigned char*)malloc(MEM_SIZE)))
        ft_error("malloc");
    while (i < MEM_SIZE)
    {
        arena[i] = 0;
        i++;
    }
    return (arena);
}

int main(int argc, char **argv)
{
    unsigned char       *arena;
    t_players         	**player_array;
    t_vm                *vm;

    player_array = ft_create_players_array(argc, argv);

    if (argc < 2)
        ft_error("no players");
    else if (argc > MAX_PLAYERS + 1)
        ft_error("to much players");
    else
        player_array = ft_create_players_array(argc, argv);
    arena = create_arena();
    arena = fill_arena(arena, player_array, argc);

    vm = ft_create_vm(arena, player_array, argc);
    ft_print_map(vm);
    // printf("REG0: %u\n", vm->players[0]->rg);
	play(vm);//


    


    return (0);
}

