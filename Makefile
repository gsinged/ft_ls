# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 19:52:40 by gsinged           #+#    #+#              #
#    Updated: 2019/12/12 22:12:10 by gsinged          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_delpath.c \
      ft_delstructure.c \
      ft_fcomb.c \
      ft_getfield.c \
      ft_getmask.c \
      ft_getminsq.c \
      ft_getpath.c \
      ft_inputvalid.c \
      ft_openfile.c \
      ft_printerror.c \
      ft_printres.c \
      ft_separate.c \
      ft_find.c \
      main_gsinged.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

HEADER = -c -I fillit.h fillit_gsinged.h

all: $(NAME)

$(OBJ): %.o: %.c
	-@ gcc -c -Wall -Werror -Wextra -I libft/ $< -o $@

$(LIBFT):
	-@ make -C libft

$(NAME): $(LIBFT) $(OBJ)
	-@ gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	-@ /bin/rm -f $(OBJ)
	-@ make -C libft clean

fclean: clean
	-@ /bin/rm -f $(NAME)
	-@ make -C libft fclean

re: fclean all