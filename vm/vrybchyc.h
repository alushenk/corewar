/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrybchyc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:31:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/04 13:23:25 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VRYBCHYC_H
# define VRYBCHYC_H

/*
** vm.current_cycle - cycle in current period
** vm.*players - array of players
**
** player.lives - count of lives in current period
*/

typedef struct		s_vm
{
	char			*arena;
	int				cycle_to_die;
	int				cycle;
	int				current_cycle;
	int				max_checks;
	t_player		*players;
	int				players_count;
}					t_vm

typedef struct		s_player
{
	int				name;
	unsigned int	rgstrs[REG_NUMBER];
	unsigned int	pc;
	int				alive;
	int				carry;
	int				cycle;
	int				lives;
	int				last_live;
}					t_player;

#endif
