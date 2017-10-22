/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zjmp_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 20:05:10 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/14 20:12:53 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

char	**zm(char *s, char **v)
{
	char	**t;
	char	*yoyo;

	if (check_operation(s) == -1)
		return (NULL);
	if ((yoyo = ft_strstr(s, "zjmp ")) != NULL)
		*v = "09";
	else if ((yoyo = ft_strstr(s, "lfork ")) != NULL)
		*v = "0f";
	else if ((yoyo = ft_strstr(s, "fork ")) != NULL)
		*v = "0c";
	t = ft_strsplit(yoyo, ' ');
	return (t);
}
