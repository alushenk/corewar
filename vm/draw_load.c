/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:23:01 by vrudenko          #+#    #+#             */
/*   Updated: 2017/09/07 12:15:52 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ft_math_cycles(int *cycle_count, int *percent_loaded)
{
	int				cycle_to_die;
	int				cycles;

	cycles = 0;
	cycle_to_die = CYCLE_TO_DIE;
	*cycle_count = 0;
	*percent_loaded = 0;
	while (cycle_to_die > 0)
	{
		cycles += cycle_to_die;
		cycle_to_die -= CYCLE_DELTA;
	}
	ft_putnbr(cycles);
	ft_putstr("\n");
	return (cycles / 100);
}

void		ft_draw_loading(int *cycle_count, int *percent_loaded,
			char *load_line, int *cycles_load)
{
	*cycle_count += 1;
	if (*cycle_count % *cycles_load == 0)
	{
		ft_putstr("\e[1;1H\e[2J");
		ft_putstr("\x1b[31m");
		ft_putstr("Loaded ");
		ft_putnbr(*percent_loaded);
		ft_putstr("% ");
		ft_putstr(load_line);
		ft_putstr("\n");
		ft_putstr("\x1b[0m");
		*percent_loaded += 1;
		load_line[*percent_loaded / 5] = '#';
		load_line[0] = '[';
	}
}

void		ft_draw_loaded(char *load_line)
{
	ft_putstr("\e[1;1H\e[2J");
	ft_putstr("\x1b[32m");
	ft_putstr("Loaded 100% [####################]\n");
	ft_putstr("\x1b[0m");
	free(load_line);
}

char		*ft_create_load_line(void)
{
	char	*load_line;

	load_line = ft_strnew(22);
	ft_strcpy(load_line, "[                    ]");
	return (load_line);
}

void		ft_use_graphics(void)
{
	char	buffer[2];

	buffer[1] = '\0';
	ft_putstr("\n\nOpen visualization? [y/n] ");
	read(0, buffer, 1);
	if (buffer[0] == 'y')
		execl("../visual/main.py", "", "output", 0);
}
