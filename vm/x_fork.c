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

t_player	*ft_create_new_player(t_player *player, unsigned int new_pc)
{
	t_player	*new_player;
	int			i;

	i = 0;
	new_player = (t_player*)malloc(sizeof(*new_player));
	new_player->name = player->name;
	while (i < REG_NUMBER)
	{
		new_player->rgstrs[i] = player->rgstrs[i];
		i++;
	}
	new_player->pc = new_pc;
	new_player->alive = player->alive;
	new_player->carry = player->carry;
	new_player->cycle = player->cycle;
	new_player->lives = player->lives;
	new_player->last_live = player->last_live;
	return (new_player);
}

void		ft_add_new_player(t_vm *vm, t_player *new_player)
{
	t_player	*new_players_array;

	int 		i;

	i = 0;
	vm->players_count += 1;
	new_players_array =  (t_player*)malloc(sizeof(t_player) * vm->players_count + 1);

	while (i < vm->players_count - 1)
	{
		new_players_array[i] = vm->players[i];
		i++;
	}
	new_players_array[i] = *new_player;
	free(vm->players);
	vm->players = new_players_array;

}

void			x_fork(t_player *player, t_vm *vm)
{
	unsigned int	argv1;
	unsigned int	new_pc;
	t_player		*new_player;
	int				tmp;
	int             addr;

	addr = (int)player->pc;
	player->pc = (player->pc + 1) % MEM_SIZE;
	argv1 = ft_get_n_bytes(vm->arena, player->pc, 2);  // 2 или 4???
	new_pc = argv1 % IDX_MOD;
	tmp = (int)new_pc;
	addr = addr + tmp;
	addr = addr % MEM_SIZE;
    if (addr < 0)
        addr += MEM_SIZE;
	new_pc = (unsigned int)addr;
	new_player = ft_create_new_player(player, new_pc);
	ft_add_new_player(vm, new_player);	
}