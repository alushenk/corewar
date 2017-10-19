/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lkorvar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:48:30 by opanchen          #+#    #+#             */
/*   Updated: 2017/10/19 17:56:07 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LKORVAR_H
# define LKORVAR_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "get_next_line.h"
# include "op.h"

typedef	struct	s_lol
{
	int			*a;
	char		*s;
	char		*lable;
	int			y;
}				t_lol;

typedef struct	s_pop
{
	char		*s;
	int			i;
}				t_pop;

typedef struct	s_ldi
{
	char		**t;
	int			i;
	int			k;
	char		*stars;
}				t_ldi;

int				check_file(char *s);
int				open_s_file(char *s, char **y);
char			*pars_lable(char *s);
int				islable(char *s, int i);
int				name_coment(char *s, char **d);
int				iscorect_lable(char *s);
int				is_la(char c);
int				one_operation_per_line(char *s);
int				check_operation(char *str);
void			del_tab(char *s);
int				*kk(char *s, int *t, char **data, struct s_lol *st);
int				find_operation(char *s, char **d, struct s_lol *st, int *a);
char			*check_arguments_live(char *s, char **da, struct s_lol *st);
char			*check_arguments_sti(char *s, char **data, struct s_lol *st);
char			*check_arguments_and(char *s, char **data, struct s_lol *st);
char			*check_arguments_zjmp(char *s, char **data, struct s_lol *st);
char			*check_arguments_st(char *t, char **data, struct s_lol *st);
char			*check_arguments_add(char *t);
char			*check_arguments_ldi(char *s, char **data, struct s_lol *st);
char			*check_arguments_lld(char *s, char **data, struct s_lol *st);
char			*check_arguments_aff(char *s);
void			transform_name(char *name, char **data);
int				get_digit(unsigned long long int value, int base);
char			*ft_itoa_base(long long int value, int base);
void			transform_coment(char *name, char **data);
void			print_data(char **data);
char			*pres(long long int k);
void			stars_arg(char *s, char **data);
int				transform(char *s);
char			*pres_4(long long int k);
void			check_lable_is(char *l, char *str, char **d, struct s_lol *st);
void			znak_voprosa(char **t, int *a, char **data, char **str);
void			change_silky(char **data, int a, int *l);
void			silka(char **v, char **data, struct s_lol *st, int ii);
char			*silka_4(char **v, char **data, struct s_lol *st, int ii);
int				del_all_coment(char **s);
char			*name_trans(int *i, char *s);
char			*coment_trans(int *i, char *s);
void			calc(char **data);
int				name_coment_1(char *s, char **data);
void			kripo(char *lable, char **data, struct s_lol *st);
int				is_normas(char *s, char *t);
int				write_file(char *data, char *s);
int				hex(char c);
int				mane_2(int *i, char *s, char **data);
char			*changes(char *s);
int				come_2(int *i, char *s, char **data);
int				chenos(char *s, int *i, int *k);
int				cle_1(char *s, int *i, int *k, char *coment);
int				na_co_la(char **s, char *ac, char **data, struct s_lol *st);
int				bet_main(char *ac);
int				find_operation_1(char *s, char **d, struct s_lol *st, int *a);
int				find_operation_2(char *s, char **d, struct s_lol *st, int *a);
int				find_operation_3(char *s, char **d, struct s_lol *st, int *a);
char			**live_1(char *s);
int				live_2(struct s_pop *r, char **d, struct s_lol *st, char **v);
void			live_3(char **t, int *i, struct s_pop *p, char **v);
int				live_1_1(char **r, char *y);
char			**ldi_1(char *s, char **v);
char			*ldi_dir(struct s_ldi *l, char **v, char **d, struct s_lol *s);
int				ildi_2(struct s_ldi *l, struct s_lol *sti, char **y);
void			ldi_3(struct s_ldi *l, char **y);
char			*ldi_reg(struct s_ldi *l, char **v);
void			ldi_ind(struct s_ldi *l, char **v);
char			*ldi_ind_1(struct s_ldi *l, char **v,
				char **d, struct s_lol *s);
int				ldi_ind_2(char **r, char *y);
int				skip(struct s_ldi *l);
int				short_ldi(struct s_ldi *l, struct s_lol *st,
				char **v, char **data);
int				short_ldi_2(struct s_ldi *l, struct s_lol *st,
				char **v, char **d);
int				ldi_4(char **r, char **y);
char			**lld_1(char *s, char **v);
int				dir_4(struct s_ldi *l, char **v, char **data, struct s_lol *st);
int				lldos(struct s_ldi *l, struct s_lol *st, char **v, char **data);
char			**sti_1(char *s, char **v);
int				short_sti(struct s_ldi *l, struct s_lol *st,
				char **v, char **data);
char			**glgl(char *s, char **v);
int				st_1(struct s_ldi *l, struct s_lol *st, char **v, char **data);
char			**add_1(char *s, char **v);
int				add_2(struct s_ldi *l, char **v);
int				down(struct s_ldi *l, char **v);
char			**and_1(char *s, char **v);
int				and_2(struct s_ldi *l, char **v, char **data, struct s_lol *st);
char			**zm(char *s, char **v);
char			**ggg(char *s, char **v);
char			*res(int i, int n, int *convert);
char			*ft_itoa_base(long long int value, int base);
void			write_data_to_file(char *data, int fd);
int				ft_16(char c);
int				ft_atoi_16(char *s);
void			k_fun(long long int *k);
void			funfun(char **data, char *a, char *b);
int				power(int x, int n);
void			dizaster(int i, char *s, int *r, char **save);
void			horos(char **f, char **data, int *y, int e);
void			gogo(char **f, struct s_lol *st, int *h, int y);
void			hoyoy(long long int *k);
void			errors(int i);
int				or_is_lable(char *lable, char *str);
int				find_operation_4(char *s, char **d, struct s_lol *st, int *a);
int				find_operation_5(char *s, char **d, struct s_lol *st, int *a);
int				find_operation_6(char *s, char **d, struct s_lol *st, int *a);
int				find_operation_7(char *s, char **d, struct s_lol *st, int *a);
void			doroy(int i);
int				empty(char *data);
int				find_i(char **s);
char			*ft_itoa_base2(long long int value, int base);
#endif
