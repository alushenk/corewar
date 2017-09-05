/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:23:01 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/04 17:05:57 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int ft_get_n_bytes(unsigned char *arena, int pc, int bytes_num)
{
    unsigned int    number;
    unsigned int    bit;
    int             byte_moovment;

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
    return (number);
}


