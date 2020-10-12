# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhori <mhori@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 11:03:08 by mhori             #+#    #+#              #
#    Updated: 2020/10/12 16:45:02 by mhori            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = 	main.c \
		get_double.c \
		get_color.c \
		get_color2.c \
		get_color3.c \
		GNL_success/get_next_line.c \
		GNL_success/get_next_line_utils.c \
		input_image.c \
		input_image2.c \
		strike_judge.c \
		vector.c \
		vector2.c \
		product.c \
		err_out_of_range.c \
		input_objs.c \
		input_objs2.c \
		change_rgb.c \
		dark.c \
		dark2.c \
		screen.c \
		cylinder.c \
		cylinder2.c \
		cylinder3.c \
		cylinder4.c \
		error.c \
		error2.c \
		utils.c \
		input_data.c \
		start_bmp.c \
		start_window.c \
		free.c \
		insert_header_data.c \
		hash.c \
		strike_judge2.c \
		strike_judge3.c \
		ft_mlx.c
OBJS = ${SRCS:.c=.o}
NAME = miniRT
LIBS = 	Libft/libft.a \
			libmlx.dylib

all: $(NAME)
	$(MAKE) -C ./Libft

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./Libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./Libft

bclean:
	rm -f *.bmp

chmod:
	chmod 700 *.bmp

re:	fclean bclean all

norme:
	norminette

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(NAME)

.PHONY: all clean fclean re bonus chmod bclean
