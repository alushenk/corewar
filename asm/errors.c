/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:18:19 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 14:22:56 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

void	errors(int i)
{
	doroy(i);
	if (i == -24)
		ft_putstr("Error in lld\n");
	if (i == -23)
		ft_putstr("Error in lldi\n");
	if (i == -22)
		ft_putstr("Error in ldi\n");
	if (i == -21)
		ft_putstr("Error in live\n");
	if (i == -20)
		ft_putstr("Can't open file\n");
	if (i == -2)
		ft_putstr("Error in .name or .coment\n");
	if (i == -3)
		ft_putstr("Error in lable\n");
	if (i == -10)
		ft_putstr("Error in coments\n");
	if (i == -1)
		ft_putstr("Error\n");
	if (i == -50)
		ft_putstr("Error: not comand\n");
}

void	doroy(int i)
{
	if (i == -36)
		ft_putstr("Error in aff\n");
	if (i == -35)
		ft_putstr("Error in fork\n");
	if (i == -34)
		ft_putstr("Error in lfork\n");
	if (i == -33)
		ft_putstr("Error in zjmp\n");
	if (i == -32)
		ft_putstr("Error in or\n");
	if (i == -31)
		ft_putstr("Error in xor\n");
	if (i == -30)
		ft_putstr("Error in and\n");
	if (i == -29)
		ft_putstr("Error in sub\n");
	if (i == -28)
		ft_putstr("Error in and\n");
	if (i == -27)
		ft_putstr("Error in st\n");
	if (i == -26)
		ft_putstr("Error in sti\n");
	if (i == -25)
		ft_putstr("Error in ld\n");
}
