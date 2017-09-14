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

// call in play.c play()
void	write_log(int fd, t_vm *vm)
{
    unsigned int    number_of_carriages;
    unsigned char   player_number;
    unsigned int    pc;

	// карта, один раз
	write(fd, vm->arena, MEM_SIZE + 1);

	// колличество кареток, один раз
	number_of_carriages = vm->players_count;
	write_int_to_file(number_of_carriages, fd);

	unsigned int i = 0;
	while (i < number_of_carriages)
	{
	    player_number = vm->players[i].name;
    	write(fd, &player_number, 1);

	    pc = vm->players[i].pc;
	    write_int_to_file(pc, fd);

	    i++;
	}
}

// call in main.c main()
int		create_log_file(t_vm *vm, t_players *initial_players)
{
	int             fd_output;
	unsigned char   number_of_players;
	unsigned char	player_number;
	unsigned int 	player_size;

	if ((fd_output = open("output", O_TRUNC | O_WRONLY | O_APPEND | O_CREAT, S_IROTH | S_IRUSR | S_IWUSR)) < 0)
	{
		write(2, "Error! can't create output file\n", ft_strlen("Error! can't create output file\n"));
		exit(0);
	}

	// колличество игроков, один раз
	number_of_players = vm->players_count;
	write(fd_output, &number_of_players, 1);

    unsigned int i = 0;
    while (i < number_of_players)
    {
        // тут начинается цикл по всем игрокам
	    player_number = vm->players[i].name * -1; // номер игрока
	    write(fd_output, &player_number, 1);

        unsigned int pc;
        pc = vm->players[i].pc;
        write_int_to_file(pc, fd_output);

	    player_size = initial_players[i].size; // размер игрока
	    write_int_to_file(player_size, fd_output);

	    write(fd_output, initial_players[i].name, PROG_NAME_LENGTH + 1);
	    write(fd_output, initial_players[i].comment, COMMENT_LENGTH + 1);

	    i++;
    }
	return (fd_output);
}

//int main(void)
//{
//	int fd;
//
//	// запускается один раз, создает файл и возвращает его дескриптор
//	fd = create_log_file();
//	// запускается много раз в цикле, внутри play()
//	// передайте в нее t_vm *vm и пишите данные от туда
//	write_log(fd);
//	return (0);
//}