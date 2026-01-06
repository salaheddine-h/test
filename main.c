/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:59:41 by salhali           #+#    #+#             */
/*   Updated: 2025/12/15 16:16:35 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	load_textures_helper(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		printf("Error: Failed to load texture: %s\n", path);
		exit(1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_length, &texture->endian);
}

void	load_textures(t_game *game)
{
	int	i;

	if (!game)
		error_print("game is NULL");
	load_textures_helper(game, &game->wall_texture[0],
		game->map->north_texture);
	load_textures_helper(game, &game->wall_texture[1],
		game->map->south_texture);
	load_textures_helper(game, &game->wall_texture[2], game->map->west_texture);
	load_textures_helper(game, &game->wall_texture[3], game->map->east_texture);
	i = 0;
	while (i < 4)
	{
		if (!game->wall_texture[i].img)
			error_print("Error in loading wall texture");
		i++;
	}
}

t_game	*g_game(void)
{
	static t_game	game;

	return (&game);
}

bool	check_file_extension(char *av)
{
	int	i;

	i = ft_strlen(av) - 4;
	if (i < 0)
		return (false);
	if (av[i] == '.' && av[i + 1] == 'c'
		&& av[i + 2] == 'u' && av[i + 3] == 'b')
		return (true);
	return (false);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
	{
		printf("Error: Invalid number of arguments.\n");
		return (1);
	}
	map = (t_map *)ft_malloc(sizeof(t_map));
	start_parsing(ac, av[1], map);
	start_game(map);
	return (0);
}
