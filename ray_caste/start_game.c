/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:03:22 by salhali           #+#    #+#             */
/*   Updated: 2026/01/06 17:27:36 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	update_game(t_game *game)
{
	if (!game)
		return ;
	mlx_clear_window(game->mlx, game->win);
	cast_all_rays(game);
	render_3d_walls(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
}

void	init_game_resources(t_game *game)
{
	t_map	*map;
	game->rays = ft_malloc(sizeof(t_ray) * SCREEN_WIDTH);
	if (!game->rays)
		error_print("Failed to allocate rays", map);
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img)
		error_print("Failed to create image", map);
	game->addr = mlx_get_data_addr(game->img, &game->bpp, &game->line_len,
			&game->endian);
}

void	init_mlx(t_game *game)
{
	t_map	*map;
	
	game->mlx = mlx_init();
	if (!game->mlx)
		error_print("Failed to initialize mlx", map);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!game->win)
		error_print("mlx_new_window failed", map);
}

void	start_game(t_map *map)
{
	t_game	*game;

	game = g_game();
	init_mlx(game);
	init_game_resources(game);
	game->map = map;
	init_keys(&game->keys);
	load_textures(game);
	update_game(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_hook(game->win, 2, 1, (int (*)())key_press, game);
	mlx_hook(game->win, 3, 2, (int (*)())key_release, game);
	mlx_loop_hook(game->mlx, (int (*)())moves, game);
	mlx_loop(game->mlx);
}
