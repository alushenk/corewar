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

static t_players	*ft_create_player_struct(unsigned char *file_str,
					int str_len)
{
	t_players	*player;

	player = (t_players*)malloc(sizeof(*player));
	player->name = (unsigned char*)ft_strnew(PROG_NAME_LENGTH);
	player->name = (unsigned char*)ft_strncpy_my((char*)player->name,
					(char*)(file_str + MAGIC_NUM_LEN), PROG_NAME_LENGTH);
	player->comment = (unsigned char*)ft_strnew(COMMENT_LENGTH);
	player->comment = (unsigned char*)ft_strncpy_my((char*)player->comment,
					(char*)(file_str + MAGIC_NUM_LEN + SIZE_PROGRAM_LEN
					+ ANOTHER_MAGIC + PROG_NAME_LENGTH), COMMENT_LENGTH);
	player->size = str_len - PROG_NAME_LENGTH - (COMMENT_LENGTH +
					MAGIC_NUM_LEN + SIZE_PROGRAM_LEN + ANOTHER_MAGIC * 2);
	player->code = (unsigned char*)ft_strnew(player->size);
	player->code = (unsigned char*)ft_strncpy_my((char*)player->code,
					((char*)(file_str
					+ MAGIC_NUM_LEN + SIZE_PROGRAM_LEN + (ANOTHER_MAGIC * 2)
					+ PROG_NAME_LENGTH + COMMENT_LENGTH)), player->size);
	free(file_str);
	return (player);
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
