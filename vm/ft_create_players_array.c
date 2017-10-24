/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_players_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lush <lush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:23:01 by vrudenko          #+#    #+#             */
/*   Updated: 2017/09/15 00:20:49 by lush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

static char			*ft_strncpy_my(char *dest, const char *src, size_t len)
{
	size_t	i;
	char	*t;

	i = 0;
	t = dest;
	while (i < len)
	{
		t[i] = src[i];
		i++;
	}
	return (dest);
}

static void			ft_norm_one(char *name)
{
	ft_putstr("\x1b[31m");
	ft_putstr(name);
	ft_error(" is too big");
}

static t_players	*ft_create_player_struct(unsigned char *file_str,
					int str_len)
{
	t_players		*p;

	if (ft_get_n_bytes(file_str, -1, 4) != COREWAR_EXEC_MAGIC)
		ft_error("this is not a champion");
	p = (t_players*)malloc(sizeof(*p));
	p->name = (unsigned char*)ft_strnew(PROG_NAME_LENGTH);
	p->name = (unsigned char*)ft_strncpy_my((char*)p->name,
					(char*)(file_str + MAGIC_NUM_LEN), PROG_NAME_LENGTH);
	p->comment = (unsigned char*)ft_strnew(COMMENT_LENGTH);
	p->comment = (unsigned char*)ft_strncpy_my((char*)p->comment,
				(char*)(file_str + MAGIC_NUM_LEN + SIZE_PROGRAM_LEN
				+ ANOTHER_MAGIC + PROG_NAME_LENGTH), COMMENT_LENGTH);
	p->size = str_len - PROG_NAME_LENGTH - (COMMENT_LENGTH +
					MAGIC_NUM_LEN + SIZE_PROGRAM_LEN + ANOTHER_MAGIC * 2);
	if (p->size >= MEM_SIZE / MAX_PLAYERS || p->size > CHAMP_MAX_SIZE)
		ft_norm_one((char*)p->name);
	p->code = (unsigned char*)ft_strnew(p->size);
	p->code = (unsigned char*)ft_strncpy_my((char*)p->code,
	((char*)(file_str + MAGIC_NUM_LEN + SIZE_PROGRAM_LEN + (ANOTHER_MAGIC * 2)
	+ PROG_NAME_LENGTH + COMMENT_LENGTH)), p->size);
	free(file_str);
	return (p);
}

static t_players	*ft_read_player_file(char *file_name)
{
	int				fd;
	int				buf[1];
	int				file_len;
	unsigned char	*file_str;

	fd = 0;
	file_len = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_error("error_file");
	while ((read(fd, buf, 1)))
		file_len++;
	lseek(fd, 0L, SEEK_SET);
	file_str = (unsigned char*)ft_strnew(file_len);
	read(fd, file_str, file_len);
	return (ft_create_player_struct(file_str, file_len));
}

t_players			**ft_create_players_array(int argc, char **argv)
{
	t_players		**players_tab;
	int				i;
	unsigned int	k;

	players_tab = (t_players**)malloc(sizeof(t_players*) * argc);
	players_tab[argc - 1] = 0;
	k = 0;
	i = 1;
	while (i < argc)
	{
		players_tab[k] = ft_read_player_file(argv[i]);
		i++;
		k++;
	}
	return (players_tab);
}
