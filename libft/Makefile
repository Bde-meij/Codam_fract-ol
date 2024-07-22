# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 15:01:52 by bde-meij          #+#    #+#              #
#    Updated: 2022/05/30 15:02:08 by bde-meij         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC	= gcc
SRC = ft_putstr_fd.c\
ft_strlen.c\
ft_strncmp.c

OBJFILES = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

OBJ = $(OBJFILES)

all	: $(NAME)

$(NAME) : $(OBJ)
	ar -csr $(NAME) $(OBJ)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all