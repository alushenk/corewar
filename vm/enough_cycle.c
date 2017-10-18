/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enough_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:33:41 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/05 11:45:16 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		enough_cycle_one(int cycle, int command)
{
	if (command == 1 && cycle == 10)
		return (1);
	else if (command == 2 && cycle == 5)
		return (1);
	else if (command == 3 && cycle == 5)
		return (1);
	else if (command == 4 && cycle == 10)
		return (1);
	else if (command == 5 && cycle == 10)
		return (1);
	else if (command == 6 && cycle == 6)
		return (1);
	else if (command == 7 && cycle == 6)
		return (1);
	else if (command == 8 && cycle == 6)
		return (1);
	return (0);
}

static int		enough_cycle_two(int cycle, int command)
{
	if (command == 9 && cycle == 20)
		return (1);
	else if (command == 10 && cycle == 25)
		return (1);
	else if (command == 11 && cycle == 25)
		return (1);
	else if (command == 12 && cycle == 800)
		return (1);
	else if (command == 13 && cycle == 10)
		return (1);
	else if (command == 14 && cycle == 50)
		return (1);
	else if (command == 15 && cycle == 1000)
		return (1);
	else if (command == 16 && cycle == 2)
		return (1);
	return (0);
}

int				enough_cycle(int cycle, int command)
{
	if (command < 1 || command > 16)
		return (1);
	if (enough_cycle_one(cycle, command) || enough_cycle_two(cycle, command))
		return (1);
	else
		return (0);
}

