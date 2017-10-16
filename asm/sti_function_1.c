/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_function_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 00:29:42 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/16 00:39:51 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		power(int x, int n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (1 / (x * power(1 / x, n + 1)));
	return (x * power(x, n - 1));
}
