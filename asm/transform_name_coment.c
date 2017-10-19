/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_name_coment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 00:44:02 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 17:58:41 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

void	transform_name(char *name, char **data)
{
	int		i;
	char	*s;

	*data = "";
	*data = ft_strjoin(*data, "00ea83f3");
	i = 0;
	while (name[i] != '\0')
	{
		s = ft_itoa_base2(name[i], 16);
		*data = ft_strjoin(*data, s);
		i++;
	}
	while (i < PROG_NAME_LENGTH + 4)
	{
		*data = ft_strjoin(*data, "00");
		i++;
	}
	*data = ft_strjoin(*data, "********");
}

void	transform_coment(char *name, char **data)
{
	int		i;
	char	*s;

	i = 0;
	while (name[i] != '\0')
	{
		s = ft_itoa_base2(name[i], 16);
		*data = ft_strjoin(*data, s);
		i++;
	}
	while (i < COMMENT_LENGTH + 4)
	{
		*data = ft_strjoin(*data, "00");
		i++;
	}
}

char	*res(int i, int n, int *convert)
{
	char		*base;
	char		*res;

	base = "0123456789abcdef";
	res = (char *)malloc(i * sizeof(res));
	i--;
	if (n == 1)
		res[0] = '-';
	while (i >= 0)
	{
		res[n] = base[convert[i]];
		n++;
		i--;
	}
	res[n] = '\0';
	return (res);
}

char	*ft_itoa_base(long long int value, int base)
{
	long long int	val;
	int				i;
	int				n;
	int				convert[64];

	val = value;
	n = 0;
	if (val < 0)
	{
		val *= -1;
		if (base == 10)
			n = 1;
	}
	i = 0;
	if (val == 0)
		return ("0");
	while (val != 0)
	{
		convert[i++] = val % base;
		val = val / base;
	}
	return (res(i, n, convert));
}

char	*ft_itoa_base2(long long int value, int base)
{
	long long int	val;
	int				i;
	int				n;
	int				convert[64];

	if (value == 10)
		return ("0a");
	val = value;
	n = 0;
	if (val < 0)
	{
		val *= -1;
		if (base == 10)
			n = 1;
	}
	i = 0;
	if (val == 0)
		return ("0");
	while (val != 0)
	{
		convert[i++] = val % base;
		val = val / base;
	}
	return (res(i, n, convert));
}
