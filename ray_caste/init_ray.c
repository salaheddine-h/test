/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:00:15 by fahosni           #+#    #+#             */
/*   Updated: 2025/12/08 12:00:20 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	init_ray_position(t_raycast *r, t_ray_coords *c)
{
	r->map_x = (int)(c->player_x / TILE_SIZE);
	r->map_y = (int)(c->player_y / TILE_SIZE);
}

static void	init_ray_direction(t_raycast *r, double ray_angle)
{
	r->ray_angle = ray_angle;
	r->raydirx = cos(ray_angle);
	r->raydiry = sin(ray_angle);
	r->delta_x = safe_inverse(r->raydirx);
	r->delta_y = safe_inverse(r->raydiry);
	r->hit = 0;
}

static void	init_ray_step_x(t_raycast *r, double px)
{
	if (r->raydirx < 0)
	{
		r->step_x = -1;
		r->side_distx = (px - r->map_x * TILE_SIZE) * r->delta_x / TILE_SIZE;
	}
	else
	{
		r->step_x = 1;
		r->side_distx = ((r->map_x + 1) * TILE_SIZE - px) * r->delta_x
			/ TILE_SIZE;
	}
}

static void	init_ray_step_y(t_raycast *r, double py)
{
	if (r->raydiry < 0)
	{
		r->step_y = -1;
		r->side_disty = (py - r->map_y * TILE_SIZE) * r->delta_y / TILE_SIZE;
	}
	else
	{
		r->step_y = 1;
		r->side_disty = ((r->map_y + 1) * TILE_SIZE - py) * r->delta_y
			/ TILE_SIZE;
	}
}

void	init_ray_2d(t_raycast *r, t_ray_coords *c, double ray_angle)
{
	init_ray_position(r, c);
	init_ray_direction(r, ray_angle);
	init_ray_step_x(r, c->player_x);
	init_ray_step_y(r, c->player_y);
}
