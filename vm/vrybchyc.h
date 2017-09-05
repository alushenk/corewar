/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrybchyc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:31:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/05 13:14:02 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VRYBCHYC_H
# define VRYBCHYC_H
# include "vrudenko.h"

/*
** vm.current_cycle - cycle in current period
** vm.*players - array of players
**
** player.lives - count of lives in current period
*/

void		play(t_vm *vm);
void		move(t_player *player, t_vm *vm);
int			enough_cycle(int cycle, int command);

void		x_live(t_player *player, t_vm *vm);
void		x_ld(t_player *player, unsigned char *arena);
void		x_st(t_player *player, unsigned char *arena);


#endif
