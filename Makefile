# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/29 17:47:30 by salhali           #+#    #+#              #
#    Updated: 2025/12/15 16:22:00 by fahosni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -w #-g3 -fsanitize=address

FLAGS = -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC =   src/error_handel.c \
        src/file_parser.c \
        src/map_init.c \
        src/map_parser.c \
        src/parser_colors.c \
        src/parse_textures.c \
        src/parsing.c \
        src/utils1.c \
        src/utils2.c \
        gnl/get_next_line_utils.c \
        gnl/get_next_line.c \
        ray_caste/start_game.c \
        ray_caste/close_window.c \
        ray_caste/key_press.c \
        ray_caste/put_pixel.c \
        ray_caste/ray_2d.c \
        ray_caste/moves.c \
        ray_caste/is_wall.c \
        ray_caste/init_ray.c \
        ray_caste/ray_3d.c \
        ray_caste/moves_2.c \
        ray_caste/texture_utils.c \
        allocation.c \
        cleanup.c \
        main.c \
        

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

push: fclean
	git add .
	git commit -m "push"
	git push


re : fclean all

.PHONY: all clean fclean re
