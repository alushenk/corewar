/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:23:01 by vrudenko          #+#    #+#             */
/*   Updated: 2017/09/07 12:15:52 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int ft_get_n_bytes(unsigned char *arena, int pc, int bytes_num)
{
   int    number;
   int    bit;
   int             byte_moovment;
   int		bts;

   bts = bytes_num;
    number = 0;
    byte_moovment = 0;
    while (bytes_num)
    {
        bit = 0;
        bit = arena[(pc + bytes_num) % MEM_SIZE];
        bit = bit << byte_moovment;
        byte_moovment += 8;
        number |= bit;
        bytes_num--;
    }
	if (number > 255 && bts == 1)
        number -= 128;
	if (number > 32767 && bts == 2)
		number -= 65536;
	if (number > 2147483647 && bts == 4)
        number -= 2147483648;

    return (number);
}


