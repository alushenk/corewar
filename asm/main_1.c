/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:07:27 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/16 04:07:51 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

int		na_co_la(char **s, char *ac, char **data, struct lol *st)
{
	if (open_s_file(ac, s) == -1)
		return (-1);
	if (del_all_coment(s) == -1)
		return (-1);
	if (name_coment(*s, data) == -1)
	{
		if (name_coment_1(*s, data) == -1)
			return (-1);
	}
	if (((*st).lable = pars_lable(*s)) == NULL)
		return (-1);
	return (0);
}

int		bet_main(char *ac)
{
	struct lol	st;
	char		*s;
	char		*data;

	s = "";
	data = "";
	if (check_file(ac) == 1)
	{
		if (na_co_la(&s, ac, &data, &st) == -1)
			return (-1);
		if (kk(s, st.lable, &data, &st) == NULL)
			return (-1);
		calc(&data);
		kripo(st.lable, &data, &st);
		write_file(data, ac);
	}
	else
		return (-1);
	return (0);
}
