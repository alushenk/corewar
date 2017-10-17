/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lush <lush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:02:18 by alushenk          #+#    #+#             */
/*   Updated: 2017/10/06 11:59:04 by lush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				write_buf(unsigned char value, FILE *fd, t_buffer *buffer)
{
	if (buffer->size < SIZE)
	{
		buffer->data[buffer->size] = value;
		buffer->size += 1;
	}
	else
	{
		fwrite(buffer->data, 1, SIZE, fd);
		buffer->size = 0;
	}
}

void				write_int_to_file(unsigned int value, FILE *fd)
{
	unsigned char	temp;

	temp = (value >> (8 * 3)) & 0xFF;
	fwrite(&temp, 1, 1, fd);
	temp = (value >> (8 * 2)) & 0xFF;
	fwrite(&temp, 1, 1, fd);
	temp = (value >> (8 * 1)) & 0xFF;
	fwrite(&temp, 1, 1, fd);
	temp = value & 0xFF;
	fwrite(&temp, 1, 1, fd);
}

void				write_int_to_buf(unsigned int value,
					FILE *fd, t_buffer *buffer)
{
	unsigned char	temp;

	temp = (value >> (8 * 3)) & 0xFF;
	write_buf(temp, fd, buffer);
	temp = (value >> (8 * 2)) & 0xFF;
	write_buf(temp, fd, buffer);
	temp = (value >> (8 * 1)) & 0xFF;
	write_buf(temp, fd, buffer);
	temp = value & 0xFF;
	write_buf(temp, fd, buffer);
}

void				write_log(FILE *fd, t_vm *vm)
{
	unsigned int	pc;
	unsigned int	last_live;
	unsigned int	lives_in_period;
	int				i;

	i = 0;
	while (i < MEM_SIZE + 1)
		write_buf(vm->arena[i++], fd, vm->buffer);
	write_int_to_buf(vm->players_count, fd, vm->buffer);
	i = 0;
	while (i < vm->players_count)
	{
		write_buf(vm->players[i].name * -1, fd, vm->buffer);
		pc = vm->players[i].pc;
		write_int_to_buf(pc, fd, vm->buffer);
		write_buf(vm->players[i].is_change, fd, vm->buffer);
		vm->players[i].is_change = 0;
		write_int_to_buf(vm->players[i].addr_of_change, fd, vm->buffer);
		last_live = vm->players[i].last_live;
		write_int_to_buf(last_live, fd, vm->buffer);
		lives_in_period = vm->players[i].lives;
		write_int_to_buf(lives_in_period, fd, vm->buffer);
		i++;
	}
}

FILE				*create_log_file(t_vm *vm, t_players **init_players)
{
	FILE			*fd_output;
	unsigned char	number_of_players;
	unsigned char	player_number;
	unsigned int	n[3];

	vm->buffer = (t_buffer*)malloc(sizeof(t_buffer));
	vm->buffer->data = (unsigned char*)malloc(SIZE);
	vm->buffer->size = 0;
	fd_output = fopen("output", "w");
	number_of_players = vm->players_count;
	fwrite(&number_of_players, 1, 1, fd_output);
	n[2] = 0;
	while (n[2] < number_of_players)
	{
		player_number = vm->players[n[2]].name * -1;
		fwrite(&player_number, 1, 1, fd_output);
		n[1] = vm->players[n[2]].pc;
		write_int_to_file(n[1], fd_output);
		n[0] = init_players[n[2]]->size;
		write_int_to_file(n[0], fd_output);
		fwrite(init_players[n[2]]->name, 1, PROG_NAME_LENGTH + 1, fd_output);
		fwrite(init_players[n[2]]->comment, 1, COMMENT_LENGTH + 1, fd_output);
		n[2]++;
	}
	return (fd_output);
}
