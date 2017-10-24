/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 12:30:36 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/05 13:30:29 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				ft_error(char *error_name)
{
	ft_putstr("\x1b[31m");
	ft_putstr(error_name);
	ft_putstr("\n");
	ft_putstr("\x1b[0m");
	exit(0);
}

unsigned char		*fill_arena(unsigned char *arena,
					t_players **players, int argc)
{
	int				delta;
	int				i;
	unsigned int	k;

	i = 0;
	delta = MEM_SIZE / (argc - 1);
	while (i < argc - 1)
	{
		k = 0;
		while (k < players[i]->size)
		{
			arena[(i * delta) + k] = players[i]->code[k];
			k++;
		}
		i++;
	}
	return (arena);
}

unsigned char		*create_arena(void)
{
	unsigned char	*arena;
	int				i;

	i = 0;
	if (!(arena = (unsigned char*)malloc(MEM_SIZE)))
		ft_error("malloc");
	while (i < MEM_SIZE)
	{
		arena[i] = 0;
		i++;
	}
	return (arena);
}

void				ft_free_memory(unsigned char *arena, t_vm *vm,
					t_players **player_array, int argc)
{
	int i;

	i = 0;
	if (player_array != NULL)
	{
		while (i < argc - 1)
		{
			free(player_array[i]->name);
			free(player_array[i]->comment);
			free(player_array[i]->code);
			free(player_array[i]);
			i++;
		}
		free(player_array);
	}
	free(vm->buffer->data);
	free(vm->buffer);
	free(vm->players);
	free(vm);
	free(arena);
}

int					main(int argc, char **argv)
{
	unsigned char		*arena;
	t_players			**player_array;
	t_vm				*vm;
	FILE				*fd;

	player_array = NULL;
	ft_validation(argc, argv);
	player_array = ft_create_players_array(argc, argv);
	arena = create_arena();
	arena = fill_arena(arena, player_array, argc);
	vm = ft_create_vm(arena, player_array, argc);
	fd = create_log_file(vm, player_array);
	play(vm, fd);
	if (vm->buffer->size > 0)
		fwrite(vm->buffer->data, 1, vm->buffer->size, fd);
	ft_putstr("===============Players============\n");
	ft_print_info(vm, player_array, argc);
	ft_free_memory(arena, vm, player_array, argc);
	fclose(fd);
	ft_use_graphics();
	return (0);
}
