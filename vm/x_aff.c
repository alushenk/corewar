/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:44:07 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/09 11:50:37 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void        x_aff(t_player *player, unsigned char *arena)
{
	unsigned int	arg1;

	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arena[player->pc] != 64)
		return ;
	arg1 = ft_get_n_bytes(arena, player->pc, 1);
	player->pc = (player->pc + 1) % MEM_SIZE;
	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arg1 < 1 || arg1 > REG_NUMBER)
		return ;
	arg1 = player->rgstrs[arg1 - 1];
	arg1 = arg1 % 256;
	ft_putchar((arg1 & 0xFF000000) >> 24);
	ft_putchar((arg1 & 0x00FF0000) >> 16);
	ft_putchar((arg1 & 0x0000FF00) >> 8);
	ft_putchar(arg1 & 0x000000FF);
}
