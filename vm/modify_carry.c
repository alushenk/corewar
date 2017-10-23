/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_carry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:31:57 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/23 12:42:34 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		modify_carry(t_player *player, unsigned int value)
{
	if (!value)
		player->carry = 1;
	else
		player->carry = 0;
}
