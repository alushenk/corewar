/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:09:11 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 14:16:23 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		empty(char *data)
{
	int i;

	i = 4384;
	if (data[i] == '\0')
		return (-1);
	else
		return (1);
}
