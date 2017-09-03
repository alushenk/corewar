/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrybchyc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:31:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/03 15:02:22 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VRYBCHYC_H
# define VRYBCHYC_H

typedef struct		s_vm
{
	int				cycle_to_die;
	int				cycle;
	int				max_checks;
	t_player		*players; //array
}					t_vm

typedef struct		s_playerr
{
	int				name;
	unsigned int	rgstrs[REG_NUMBER];
	unsigned int	pc;
	int				alive;
	int				carry;
	int				lives; //count of lives in current period
	int				last_live;
}					t_player;

#endif
