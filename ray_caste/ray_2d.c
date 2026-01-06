/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:01:16 by fahosni           #+#    #+#             */
/*   Updated: 2025/12/08 12:01:17 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

double	safe_inverse(double value)
{
	if (value == 0)
		return (0);
	return (fabs(1.0 / value));
}

static void	step_ray(t_raycast *r)
{
	if (r->side_distx < r->side_disty)
	{
		r->side_distx += r->delta_x;
		r->map_x += r->step_x;
		r->side = 0;
	}
	else
	{
		r->side_disty += r->delta_y;
		r->map_y += r->step_y;
		r->side = 1;
	}
}

void	calculate_hit_point(t_raycast *r, t_ray_coords *c)
{
	double	dist;

	if (r->side == 0)
		dist = r->side_distx - r->delta_x;
	else
		dist = r->side_disty - r->delta_y;
	c->hit_x = c->player_x + r->raydirx * dist * TILE_SIZE;
	c->hit_y = c->player_y + r->raydiry * dist * TILE_SIZE;
}

int	raycast_loop(t_game *game, t_raycast *r)
{
	while (r->hit == 0)
	{
		step_ray(r);
		if (r->map_y < 0 || r->map_x < 0 || r->map_y >= game->map->map_height
			|| r->map_x >= (int)ft_strlen(game->map->map[r->map_y]))
			return (0);
		if (game->map->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
	return (r->hit);
}
