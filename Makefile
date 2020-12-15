# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 17:39:37 by ckurt             #+#    #+#              #
#    Updated: 2020/12/15 13:25:44 by ckurt            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_PURPLE=\033[35m
_CYAN=\033[36m
_WHITE=\033[37m

_IGREY=\033[40m
_IRED=\033[41m
_IGREEN=\033[42m
_IYELLOW=\033[43m
_IBLUE=\033[44m
_IPURPLE=\033[45m
_ICYAN=\033[46m
_IWHITE=\033[47m

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
NAME = libftprintf.a
SRCS = src/ft_printf.c
OBJS = $(SRCS:.c=.o)

.c.o:
	@printf "$(_CYAN) [+] $(_END) Compiling $(_BLUE)owo $(_END)$<\n" | tr "lr" "w"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@cp ./libft/libft.a $(NAME)
	@$(LIBC) $(NAME) $(OBJS)

test: $(NAME)
	$(CC) -L ./ $(NAME) src/main.c && ./a.out

re: fclean
	@$(MAKE) all

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJS)
	@printf "$(_RED) [-] $(_END) Deleted objs\n"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

.PHON: clean fclean re all