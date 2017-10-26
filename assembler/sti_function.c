/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 11:43:24 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/16 00:29:12 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lkorvar.h"

void	k_fun(long long int *k)
{
	while (*k > 65536)
		*k = *k - 65536;
	while (*k < -65536)
		*k = *k + 65536;
	if (*k < 0)
		*k = *k + 65536;
}

char	*pres(long long int k)
{
	char	*s;
	char	*r;
	int		i;
	int		j;

	k_fun(&k);
	s = ft_itoa_base(k, 16);
	r = (char *)malloc(sizeof(char) * 4);
	r[3] = '\0';
	i = -1;
	while (++i != 3)
		r[i] = 'p';
	j = ft_strlen(s);
	while (--j >= 0)
	{
		r[i] = s[j];
		i--;
	}
	i = -1;
	while (r[++i] != 0)
	{
		if (r[i] == 'p')
			r[i] = '0';
	}
	return (r);
}

void	stars_arg(char *s, char **data)
{
	int		j;
	char	*y;
	char	*a;
	char	*b;
	int		i;

	j = -1;
	y = ft_strnew(8);
	while (s[++j] != '\0')
		y[j] = s[j];
	j--;
	while (++j != 9)
		y[j] = '0';
	j = -1;
	a = ft_strnew(4);
	b = ft_strnew(4);
	while (++j != 4)
		a[j] = y[j];
	i = -1;
	while (j != 8)
	{
		b[++i] = y[j];
		j++;
	}
	funfun(data, a, b);
}

void	funfun(char **data, char *a, char *b)
{
	int i;

	i = ft_strlen(*data);
	while ((*data)[i] != '*')
		i--;
	b = ft_itoa(transform(b));
	b = ft_itoa_base(ft_atoi(b), 16);
	(*data)[i] = b[0];
	i--;
	a = ft_itoa(transform(a));
	a = ft_itoa_base(ft_atoi(a), 16);
	(*data)[i] = a[0];
}

int		transform(char *s)
{
	int i;
	int sum;
	int j;

	i = ft_strlen(s) - 1;
	sum = 0;
	j = 0;
	while (s[j] != '\0')
	{
		sum = sum + power(2, i) * (s[j] - 48);
		i--;
		j++;
	}
	return (sum);
}
