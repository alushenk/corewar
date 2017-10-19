# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opanchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/06 12:39:22 by opanchen          #+#    #+#              #
#    Updated: 2017/10/19 15:03:27 by opanchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc

HEAD = op.h get_next_line.h lkorvar.h 

HEAD_GCH = $(HEAD:.h=.h.gch)

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  get_next_line.c \
	  open_file.c \
	  lable.c \
	  name_coment_piece.c \
	  check_operations.c \
	  del_all_tabs.c \
	  corect_operation.c \
	  check_sti.c \
	  check_and.c \
	  check_zjmp.c \
	  transform_name_coment.c \
	  sti_function.c \
	  and_function.c \
	  check_lable.c \
	  check_live.c \
	  silka.c \
	  check_st.c \
	  check_add.c \
	  check_ldi.c \
	  check_lld.c \
	  check_aff.c \
	  del_all_coment.c \
	  calculate_len.c \
	  name_coment_piece_copy.c \
	  kripto.c \
	  write_file.c \
	  name_2.c \
	  changes.c \
	  main_1.c \
	  check_ldi_1.c \
	  check_ldi_2.c  \
	  check_ldi_3.c \
	  check_lld_1.c \
	  check_sti_1.c \
	  check_and_1.c \
	  check_zjmp_1.c \
	  sti_function_1.c \
	  errors.c \
	  corect_operation_1.c \
	  empty.c \
	  finder.c

SRO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRO)
			make -C libft
			$(CC) $(FLAGS) -c $(SRC) $(HEAD)
			$(CC) $(FLAGS) -o $(NAME) $(SRO) libft/libft.a


clean:
			make clean -C ./libft
			@rm -f $(SRO) $(HEAD_GCH)

fclean:
			make fclean -C ./libft
			@make clean
			@rm -f $(NAME)

re:
	make fclean
	make all
