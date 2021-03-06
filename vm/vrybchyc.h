/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrybchyc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:31:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/23 11:47:53 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VRYBCHYC_H
# define VRYBCHYC_H
# include "vrudenko.h"
# include <stdio.h>

/*
** vm.current_cycle - cycle in current period
** vm.*players - array of players
**
** player.lives - count of lives in current period
*/

void			play(t_vm *vm, FILE *fd);
void			move(t_player *player, t_vm *vm);
int				enough_cycle(int cycle, int command);
void			x_live(t_player *player, t_vm *vm);
void			x_ld(t_player *player, unsigned char *arena);
void			x_st(t_player *player, unsigned char *arena);
void			x_add(t_player *player, unsigned char *arena);
void			x_sub(t_player *player, unsigned char *arena);
void			x_and(t_player *player, unsigned char *arena);
void			x_or(t_player *player, unsigned char *arena);
void			x_xor(t_player *player, unsigned char *arena);
int				ft_xor_five(unsigned int *as, t_player *player,
				unsigned char *arena, int *tmp);
void			ft_xor_six(unsigned int *as, t_player *player);
int				ft_or_five(unsigned int *as, t_player *player,
				unsigned char *arena, int *tmp);
void			ft_or_six(unsigned int *as, t_player *player);
int				ft_and_five(unsigned int *as, t_player *player,
				unsigned char *arena, int *tmp);
int				no_live_payers(t_vm *vm);
void			update_alive(t_vm *vm);
void			ft_and_six(unsigned int *as, t_player *player);
void			x_zjmp(t_player *player, unsigned char *arena);
void			x_ldi(t_player *player, unsigned char *arena);
void			x_sti(t_player *player, unsigned char *arena, int flag);
void			x_lld(t_player *player, unsigned char *arena);
void			x_lldi(t_player *player, unsigned char *arena, int flag);
void			x_aff(t_player *player, unsigned char *arena);
void			x_fork(t_player *player, t_vm *vm);
void			x_lfork(t_player *player, t_vm *vm);
t_player		ft_create_new_player(t_player *player, unsigned int new_pc);
void			ft_add_new_player(t_vm *vm, t_player new_player);
unsigned int	ft_addr(int tmp);
void			modify_carry(t_player *player, unsigned int value);

#endif
