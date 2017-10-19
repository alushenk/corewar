/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:00:12 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 12:16:33 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		main(int ar, char **ac)
{
	int u;

	if (ar == 2)
	{
		if ((u = bet_main(ac[1])) < 0)
		{
			errors(u);
			return (-1);
		}
	}
	else
		ft_putstr("Error in arguments\n");
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
