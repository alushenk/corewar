/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 12:30:36 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/31 18:09:58 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*fill_arena(char *arena, t_plyers *players)
{

}

char	*create_arena(void)
{
	char	*arena;
	int		i;

	i = 0;
	if (!(arena = (char*)malloc(MEM_SIZE)))
		ft_error("malloc");
	while (i < MEM_SIZE)
	{
		arena[i] = 0;
		i++;
	}
	return (arena);
}

int		main(int argc, char **argv)
{
	char		*arena;
	t_players	*players;

	if (argc < 2)
		ft_error("no players");
	else if (argc > MAX_PLAYERS + 1)
		ft_error("to much players");
	else
		players = ft_players(argc, argv);
	arena = create_arena();
	arena = fill_arena(arena, players);
	return (0);
}
