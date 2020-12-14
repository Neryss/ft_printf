# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 13:34:22 by ckurt             #+#    #+#              #
#    Updated: 2020/12/14 17:38:52 by ckurt            ###   ########lyon.fr    #
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
INCS = libft.h
LIBC = ar rcs
NAME = libft.a
SRCS = ft_memset.c \
		ft_bzero.c \
		ft_memccpy.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_atoi.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_calloc.c \
		ft_strjoin.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_putendl_fd.c \
		ft_putendl.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_split.c \
		ft_substr.c \
		ft_strtrim.c\
		ft_itoa.c \
		ft_strmapi.c \
		ft_check_whitespaces.c \
		ft_strcat.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstclear.c \
		ft_foreach.c \
		ft_freeall.c \
		ft_isalnum.c \
		ft_split_charset.c
OBJS = $(SRCS:.c=.o)

.c.o:
	@printf "$(_CYAN) [+] $(_END) Compiling $(_BLUE)owo $(_END)$<\n" | tr "lr" "w"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)
	@printf " $(_GREEN)=>$(_END) Fwinished uwu!\n"

re: fclean
	@$(MAKE) all

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

.PHONY: clean fclean re all