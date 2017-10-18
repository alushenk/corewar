/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:38:40 by vrudenko          #+#    #+#             */
/*   Updated: 2017/10/18 18:38:48 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				ft_determ_winner(t_vm *vm, t_players **players,
					char **c, int i)
{
	int		winner_number;
	int		last_life;

	winner_number = 1;
	i = 0;
	last_life = 0;
	while (i < vm->players_count)
	{
		if (vm->players[i].last_live > last_life)
		{
			last_life = vm->players[i].last_live;
			winner_number = (vm->players[i].name * (-1));
		}
		i++;
	}
	ft_putstr("-----------------------------------\n\n");
	ft_putstr("==================================\n");
	ft_putstr("🌟 🌟 🌟 🌟 🌟 🌟   WINNER  🌟 🌟 🌟 🌟 🌟 🌟\nThe winner is player: ");
	ft_putstr(c[winner_number - 1]);
	ft_putstr((const char*)players[winner_number - 1]->name);
	ft_putstr("!\n");
	ft_putstr((const char*)players[winner_number - 1]->comment);
	ft_putstr("\x1b[0m\n🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟 🌟\n");
	ft_putstr("==================================\n");
	free(c);
}

void				ft_print_info(t_vm *vm, t_players **players, int argc)
{
	int		i;
	char	**colors;

	colors = (char**)malloc(sizeof(char*) * 4);
	colors[0] = "\e[33m\0";
	colors[1] = "\e[32m\0";
	colors[2] = "\e[35m\0";
	colors[3] = "\e[34m\0";
	i = 0;
	while (i < argc - 1)
	{
		ft_putstr("-----------------------------------\n");
		ft_putstr(colors[i]);
		ft_putstr("             Player ");
		ft_putnbr(i + 1);
		ft_putstr("\nName: ");
		ft_putstr((const char*)players[i]->name);
		ft_putstr("\nSlogan: ");
		ft_putstr((const char*)players[i]->comment);
		ft_putstr("\nSize: ");
		ft_putnbr(players[i]->size);
		ft_putstr("\x1b[0m\n");
		i++;
	}
	ft_determ_winner(vm, players, colors, i);
}
