/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrybchyc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:31:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/09 11:43:57 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VRUDENKO_H
# define COREWAR_VRUDENKO_H
# include "../libft/libft.h"
# include "corewar.h"
# define MAGIC_NUM_LEN 4
# define SIZE_PROGRAM_LEN 4
# define ANOTHER_MAGIC 4
# define SIZE 4000000000

typedef struct		s_players
{
	unsigned char	*name;
	unsigned char	*comment;
	unsigned int	size;
	unsigned char	*code;
}					t_players;

typedef struct		s_player
{
	int				name;
	unsigned int	rgstrs[REG_NUMBER];
	unsigned int	pc;
	int				alive;
	int				carry;
	int				cycle;
	int				lives;
	int				last_live;
	int				is_change;
	unsigned int	addr_of_change;
}					t_player;

typedef struct		s_buffer
{
	unsigned char	*data;
	size_t			size;
}					t_buffer;

typedef struct		s_vm
{
	unsigned char	*arena;
	int				cycle_to_die;
	int				cycle;
	int				current_cycle;
	int				max_checks;
	t_player		*players;
	int				players_count;
	t_buffer		*buffer;
}					t_vm;

char				*ft_copy_str_part(int start, int size, char *str);
void				free_ass(unsigned int *as);
void				ft_error(char *error_name);
t_players			**ft_create_players_array(int argc, char **argv);
int					ft_get_n_bytes(unsigned char *arena, int pc, int bytes_num);
t_vm				*ft_create_vm(unsigned char *arena,
					t_players **players_array, int argc);
void				ft_print_info(t_vm *vm, t_players **players, int argc);
char				*ft_create_load_line(void);
void				ft_draw_loaded(char	*load_line);
void				ft_draw_loading(int *cycle_count, int *percent_loaded,
					char *load_line, int *cycles_load);
int					ft_math_cycles(int *cycle_count, int *percent_loaded);
void				ft_validation(int argc, char **argv);
void				ft_use_graphics(void);

#endif
