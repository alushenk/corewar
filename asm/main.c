/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:00:12 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/12 17:17:06 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		main(int ar, char **ac)
{
	if (ar == 2)
	{
		if (bet_main(ac[1]) == -1)
		{
			ft_putstr("Error\n");
			return (-1);
		}
	}
	else
		ft_putstr("Error\n");
	return (0);
}

int		check_file(char *s)
{
	int i;

	i = ft_strlen(s);
	if (s[i - 1] == 's')
	{
		if (s[i - 2] == '.')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
