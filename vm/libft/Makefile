# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 14:19:32 by vrudenko          #+#    #+#              #
#    Updated: 2016/12/05 15:31:23 by vrudenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = ft_memalloc.c ft_memdel.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_strclr.c ft_strdel.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c ft_strsplit.c ft_strsub.c ft_strtrim.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_runchar.c ft_runspace_back.c ft_runspace.c ft_runstr.c ft_lstpushback.c ft_lststrsplit.c ft_countsplit.c ft_list_size.c ft_strtoend.c ft_itoa.c

CC = gcc

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

INC = -Iincludes

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(INC) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
