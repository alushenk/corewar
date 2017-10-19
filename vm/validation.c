/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:46:31 by vrudenko          #+#    #+#             */
/*   Updated: 2017/10/19 15:46:39 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				ft_validation(int argc, char **argv)
{
	int		i;
	int		file_name_len;

	i = 1;
	if (argc < 2)
		ft_error("no players");
	else if (argc > MAX_PLAYERS + 1)
		ft_error("too much players");
	while (i < argc)
	{
		file_name_len = ft_strlen(argv[i]);
		if (ft_strcmp(argv[i] + file_name_len - 4, ".cor"))
			ft_error("wrong file format. use <name>.cor ");
		i++;
	}
}
