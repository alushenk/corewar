/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:07:27 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 14:47:04 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		na_co_la(char **s, char *ac, char **data, struct s_lol *st)
{
	if (open_s_file(ac, s) == -1)
		return (-20);
	if (del_all_coment(s) == -1)
		return (-10);
	if (name_coment(*s, data) == -1)
	{
		if (name_coment_1(*s, data) == -1)
			return (-1);
	}
	if (((*st).lable = pars_lable(*s)) == NULL)
		return (-3);
	return (0);
}

int		bet_main(char *ac)
{
	struct s_lol	st;
	char			*s;
	char			*data;
	int				g;

	s = "";
	data = "";
	if (check_file(ac) == 1)
	{
		if ((g = na_co_la(&s, ac, &data, &st)) < 0)
			return (g);
		if (kk(s, &g, &data, &st) == NULL)
			return (g);
		calc(&data);
		kripo(st.lable, &data, &st);
		if (empty(data) == -1)
			return (-50);
		write_file(data, ac);
	}
	else
		return (-1);
	return (0);
}
