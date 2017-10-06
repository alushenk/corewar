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

void	write_int_to_file(unsigned int value, FILE *fd)
{
	unsigned char temp;

	temp = (value >> (8 * 3)) & 0xFF;
	fwrite(&temp, 1, 1, fd);
	temp = (value >> (8 * 2)) & 0xFF;
	fwrite(&temp, 1, 1, fd);
	temp = (value >> (8 * 1)) & 0xFF;
	fwrite(&temp, 1, 1, fd);
	temp = value & 0xFF;
	fwrite(&temp, 1, 1, fd);
}

// call in play.c play()
// unsigned char *copy
void	write_log(FILE *fd, t_vm *vm)
{
    unsigned int    number_of_carriages;
    unsigned char   player_number;
    unsigned int    pc;
    unsigned int    is_change;
    unsigned int    addr_of_change;
    unsigned int i;

//    int len;
//
//	len = 0;
//	i = 0;
//	while (copy[i])
//	{
//	    if (vm->arena[i] != copy[i])
//	        len++;
//	    i++;
//	}
//	printf("\nlen: %d\n", len);
//	write_int_to_file(len, fd);
//	if (len > 0)
//	{
//	    i = 0;
//	    len = 0;
//	    while (copy[i])
//	    {
//	        if (vm->arena[i] != copy[i])
//	            write_int_to_file(len, fd);
//	            write(fd, &copy[i], 1);
//	            len++;
//	        i++;
//	    }
//	}

    fwrite(vm->arena, 1, MEM_SIZE + 1, fd);

	// колличество кареток, один раз
	number_of_carriages = vm->players_count;
	write_int_to_file(number_of_carriages, fd);

	i = 0;
	while (i < number_of_carriages)
	{
	    player_number = vm->players[i].name;
        fwrite(&player_number, 1, 1, fd);

	    pc = vm->players[i].pc;
	    write_int_to_file(pc, fd);

	    is_change = vm->players[i].is_change;
	    fwrite(&is_change, 1, 1, fd);
	    vm->players[i].is_change = 0;

	    addr_of_change = vm->players[i].addr_of_change;
	    write_int_to_file(addr_of_change, fd);

	    i++;
	}
}

// call in main.c main()
FILE		*create_log_file(t_vm *vm, t_players **initial_players)
{
	FILE            *fd_output;
	unsigned char   number_of_players;
	unsigned char	player_number;
	unsigned int 	player_size;
	unsigned int    pc;

    //O_TRUNC | O_WRONLY | O_APPEND | O_CREAT, S_IROTH | S_IRUSR | S_IWUSR
	// if ((fd_output = fopen("output", "w")) < 0)
	// {
	// 	write(2, "Error! can't create output file\n", ft_strlen("Error! can't create output file\n"));
	// 	exit(0);
	// }
	fd_output = fopen("output", "w");

	// колличество игроков, один раз
	number_of_players = vm->players_count;
	fwrite(&number_of_players, 1, 1, fd_output);

    ft_putnbr(number_of_players);
    ft_putstr("\n");

    unsigned int i = 0;
    while (i < number_of_players)
    {
        // тут начинается цикл по всем игрокам
	    player_number = vm->players[i].name * -1; // номер игрока
	    fwrite(&player_number, 1, 1, fd_output);

        pc = vm->players[i].pc;
        write_int_to_file(pc, fd_output);

	    player_size = initial_players[i]->size; // размер игрока
	    write_int_to_file(player_size, fd_output);

	    fwrite(initial_players[i]->name, 1, PROG_NAME_LENGTH + 1, fd_output);

	    ft_putnbr(i);
        ft_putstr("\n");

	    fwrite(initial_players[i]->comment, 1, COMMENT_LENGTH + 1, fd_output);

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