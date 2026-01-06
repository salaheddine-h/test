/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:33:57 by salhali           #+#    #+#             */
/*   Updated: 2025/12/05 20:09:31 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	map_init(t_map *map)
{
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_color = NULL;
	map->ceiling_color = NULL;
	map->map = NULL;
	map->player.dir = 0;
	map->player.x = -1;
	map->player.y = -1;
	map->floor_rgb.r = -1;
	map->floor_rgb.g = -1;
	map->floor_rgb.b = -1;
	map->ceiling_rgb.r = -1;
	map->ceiling_rgb.g = -1;
	map->ceiling_rgb.b = -1;
	map->map_height = 0;
}
