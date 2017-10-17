/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:32:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/01 11:39:42 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "defines.h"
# include "vrybchyc.h"
# include "vrudenko.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

FILE		*create_log_file(t_vm *vm, t_players **initial_players);
void		write_log(FILE *fd, t_vm *vm);

#endif
