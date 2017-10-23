#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/15 11:17:22 by vrybchyc          #+#    #+#              #
#    Updated: 2017/10/23 11:48:18 by vrybchyc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

SRC = 	\
		enough_cycle.c \
		ft_addr.c \
		ft_bytes_to_int.c \
		draw_load.c \
		ft_create_players_array.c \
		ft_create_vm.c \
		main.c\
		modify_carry.c\
		move.c \
		play.c \
		play_two.c \
		x_ld.c \
		x_live.c \
		x_st.c \
		x_add.c \
		x_sub.c \
		x_and.c \
		x_and_two.c \
		x_or.c \
		x_or_two.c \
		x_ldi.c \
		x_sti.c\
		x_lld.c \
		x_lldi.c \
		x_xor.c \
		x_xor_two.c \
		x_zjmp.c \
		x_fork.c \
		x_lfork.c \
		x_aff.c \
		write_log.c \
		free_ass.c \
		print_out.c\
		validation.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;1mmake vm\033[0m"
	@gcc $(FLAGS) -o $(NAME) $(OBJ) ../libft/libft.a

.c.o:
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[31mRemoving vm...\033[0m"
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)