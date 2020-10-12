# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhori <mhori@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/30 10:10:44 by mhori             #+#    #+#              #
#    Updated: 2020/07/08 12:36:41 by mhori            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
CLIBS	= -L . -lft
RM	= rm -f
AR	= ar r
BSRCS	= ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
        ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
        ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
        ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
        ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
        ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
        ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
        ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\

OBJS	= $(SRCS:%.c=%.o)
BOBJS	= $(BSRCS:%.c=%.o)
LIBNAME	= libft.h
NAME	= libft.a

all:	$(NAME)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

$(BOBJS):  $(OBJS)

bonus:$(BOBJS)
	$(AR) $(NAME) $(OBJS) $(BOBJS)
