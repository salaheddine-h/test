/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:59:57 by fahosni           #+#    #+#             */
/*   Updated: 2025/12/08 12:02:22 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	destroy_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->wall_texture[i].img)
			mlx_destroy_image(game->mlx, game->wall_texture[i].img);
		i++;
	}
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->ceiling.img)
		mlx_destroy_image(game->mlx, game->ceiling.img);
}

void	destroy_mlx_resources(t_game *game)
{
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	close_window(t_game *game)
{
	destroy_textures(game);
	destroy_mlx_resources(game);
	cleanup_game(game);
	exit(0);
	return (0);
}
