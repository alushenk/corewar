/*
** vm.current_cycle - cycle in current period
** vm.*players - array of players
**
** player.lives - count of lives in current period
*/

#ifndef COREWAR_VRUDENKO_H
#define COREWAR_VRUDENKO_H

#include <stdio.h>
#include "libft/libft.h"
#include "corewar.h"

#define MAGIC_NUM_LEN 4
#define SIZE_PROGRAM_LEN 4
#define ANOTHER_MAGIC 4


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct		s_players
{
	unsigned char 	*name;
	unsigned char 	*comment;
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
}					t_player;

typedef struct		s_vm
{
	unsigned char		*arena;
	int					cycle_to_die;
	int					cycle;
	int					current_cycle;
	int					max_checks;
	t_player			*players;
	int					players_count;
}						t_vm;


char		*ft_copy_str_part(int start, int size, char *str);
void 		ft_error(char *error_name);
t_players 	**ft_create_players_array(int argc, char **argv);
unsigned int ft_get_n_bytes(unsigned char *arena, int pc, int bytes_num);
void 		ft_print_player(t_players *player);
t_vm    	*ft_create_vm(unsigned char *arena, t_players **players_array, int argc);

void    ft_print_map(t_vm *vm, t_players **players);

#endif //COREWAR_VRUDENKO_H
