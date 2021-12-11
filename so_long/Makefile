# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 18:01:32 by fnichola          #+#    #+#              #
#    Updated: 2021/12/11 12:38:04 by obouadel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h\
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

SRCS = main.c \
	readmap.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	end_game.c \
	game_start.c \
	parse_map.c \
	images.c \
	render_game.c \
	move_handler.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME) clean

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(NAME): $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(HEADER) 
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT_LIB) $(OBJS) -o $(NAME)
	

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

bonus: 
	$(MAKE) -C  $(BONUS_DIR)
	
clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) -C  $(BONUS_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	$(MAKE) -C  $(BONUS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
