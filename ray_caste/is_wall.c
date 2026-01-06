/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:14:07 by fahosni           #+#    #+#             */
/*   Updated: 2025/12/15 16:14:09 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_wall(t_map *map, double x, double y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(x / TILE_SIZE);
	grid_y = (int)(y / TILE_SIZE);
	if (grid_y < 0 || grid_x < 0 || grid_y >= map->map_height
		|| !map->map[grid_y] || map->map[grid_y][grid_x] == '\0')
		return (1);
	if (map->map[grid_y][grid_x] == '1')
		return (1);
	return (0);
}
