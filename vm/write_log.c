/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:02:18 by alushenk          #+#    #+#             */
/*   Updated: 2017/09/07 20:02:20 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *temp;

	temp = s;
	while (n > 0)
	{
		*temp = 0;
		temp++;
		n--;
	}
}

void	write_int_to_file(unsigned int value, int fd)
{
	unsigned char temp;

	temp = (value >> (8 * 3)) & 0xFF;
	write(fd, &temp, 1);
	temp = (value >> (8 * 2)) & 0xFF;
	write(fd, &temp, 1);
	temp = (value >> (8 * 1)) & 0xFF;
	write(fd, &temp, 1);
	temp = value & 0xFF;
	write(fd, &temp, 1);
}

// передать сюда t_vm *vm
void	write_log(int fd)
{
    unsigned char   map[MEM_SIZE + 1];
    unsigned int    number_of_carriages;
    unsigned char   player_number;
    unsigned int    pc;

	// карта, один раз
	ft_bzero(map, MEM_SIZE + 1); // это для дебага, когда будешь писать карту это надо убрать
	map[4093] = 0x6D;
	map[4094] = 0x61;
	map[4095] = 0x70;
	write(fd, map, MEM_SIZE + 1);

	// колличество кареток, один раз
	number_of_carriages = 1;
	write_int_to_file(number_of_carriages, fd);

	// каретки игроков, в цикле while(number_of_carriages)
	player_number = 5;
	write(fd, &player_number, 1);

	pc = 4000;
	write_int_to_file(pc, fd);
}

// передать сюда t_vm *vm
// пока пишу случайные тестовые данные
int		create_log_file(void)
{
	int             fd_output;
	unsigned char   number_of_players;
	unsigned char	player_number;
	unsigned int 	player_size;
	char			prog_name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];

	if ((fd_output = open("output", O_TRUNC | O_WRONLY | O_APPEND | O_CREAT, S_IROTH | S_IRUSR | S_IWUSR)) < 0)
	{
		write(2, "Error! can't create output file\n", ft_strlen("Error! can't create output file\n"));
		exit(0);
	}

	// колличество игроков, один раз
	number_of_players = 1;
	write(fd_output, &number_of_players, 1);

	// тут начинается цикл по всем игрокам
	player_number = 1; // номер игрока
	write(fd_output, &player_number, 1);

	player_size = 25; // размер игрока
	write_int_to_file(player_size, fd_output);

	ft_bzero(prog_name, PROG_NAME_LENGTH + 1);
	prog_name[0] = 'z';
	prog_name[1] = 'o';
	prog_name[2] = 'r';
	prog_name[3] = 'k';
	write(fd_output, prog_name, PROG_NAME_LENGTH + 1);

	ft_bzero(comment, COMMENT_LENGTH + 1);
	comment[4] = 'h';
	comment[5] = 'u';
	comment[6] = 'y';
	write(fd_output, comment, COMMENT_LENGTH + 1);

	return (fd_output);
}

int main(void)
{
	int fd;

	// запускается один раз, создает файл и возвращает его дескриптор
	fd = create_log_file();
	// запускается много раз в цикле, внутри play()
	// передайте в нее t_vm *vm и пишите данные от туда
	write_log(fd);
	return (0);
}