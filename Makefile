# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 17:39:37 by ckurt             #+#    #+#              #
#    Updated: 2020/12/12 17:53:44 by ckurt            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
NAME = libftprintf.a
SRCS = src/ft_printf.c
OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	$(LIBC) $(NAME) $(OBJS)

re: fclean
	$(MAKE) all
	
clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

.PHON: clean fclean re all