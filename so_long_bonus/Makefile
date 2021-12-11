# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 18:01:32 by fnichola          #+#    #+#              #
#    Updated: 2021/12/11 16:00:14 by obouadel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long_bonus

HEADER = so_long_bonus.h\
		gnl/get_next_line.h\
		libft/libft.h\

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

BONUS_DIR = ../so_long_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = main_bonus.c \
	readmap_bonus.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	end_game_bonus.c \
	game_start_bonus.c \
	parse_map_bonus.c \
	images_bonus.c \
	render_game_bonus.c \
	move_handler_bonus.c \
	enemy_bonus.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME) clean

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(NAME): $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(HEADER) 
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT_LIB) $(OBJS) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
	
clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	clear

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	clear

re: fclean all

.PHONY: all clean fclean re bonus
