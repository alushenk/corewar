#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/15 11:17:22 by vrybchyc          #+#    #+#              #
#    Updated: 2017/09/05 17:33:29 by vrybchyc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

SRC = 	DEBUGG.c \
		enough_cycle.c \
		ft_bytes_to_int.c \
		ft_create_players_array.c \
		ft_create_vm.c \
		main.c\
		move.c \
		play.c \
		x_ld.c \
		x_live.c \
		x_st.c \
		x_add.c \
		x_sub.c \
		x_and.c \
		x_or.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;1mmake libft...\033[0m"
	@make -C libft/
	@echo "\033[32;1mmake vm\033[0m"
	@gcc $(FLAGS) -o $(NAME) -L libft/ -lft $(OBJ)

.c.o:
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@echo "\033[31mRemoving vm...\033[0m"
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norme:
	norminette $(SRC)