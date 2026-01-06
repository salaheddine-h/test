/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:01:29 by salhali           #+#    #+#             */
/*   Updated: 2025/12/15 16:14:58 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	cast_all_rays(t_game *game)
{
	int		i;
	double	angle_step;
	double	ray_angle;

	angle_step = (FOV_ANGLE * M_PI / 180.0) / SCREEN_WIDTH;
	ray_angle = (game->map->player.angle * M_PI / 180.0) - ((FOV_ANGLE * M_PI
				/ 180.0) / 2);
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		cast_single_ray(game, i, ray_angle);
		ray_angle += angle_step;
		i++;
	}
}

void	cast_single_ray(t_game *game, int i, double ray_angle)
{
	double			dx;
	double			dy;
	t_raycast		r;
	t_ray_coords	c;

	c.player_x = game->map->player.x;
	c.player_y = game->map->player.y;
	init_ray_2d(&r, &c, ray_angle);
	if (raycast_loop(game, &r))
		calculate_hit_point(&r, &c);
	dx = c.hit_x - c.player_x;
	dy = c.hit_y - c.player_y;
	game->rays[i].distance = sqrt(dx * dx + dy * dy);
	game->rays[i].angle = ray_angle;
	game->rays[i].hit_x = c.hit_x;
	game->rays[i].hit_y = c.hit_y;
	game->rays[i].side = r.side;
	game->rays[i].raydirx = r.raydirx;
	game->rays[i].raydiry = r.raydiry;
}

void	draw_floor_and_ceiling(t_game *game, int x)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = (game->map->ceiling_rgb.r << 16)
		| (game->map->ceiling_rgb.g << 8) | game->map->ceiling_rgb.b;
	floor_color = (game->map->floor_rgb.r << 16)
		| (game->map->floor_rgb.g << 8) | game->map->floor_rgb.b;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < SCREEN_HEIGHT / 2)
			put_pixel(game, x, y, ceiling_color);
		else
			put_pixel(game, x, y, floor_color);
		y++;
	}
}

void	draw_wall_strip(t_game *game, int x, double player_angle_rad)
{
	t_ray			*ray;
	t_texture		*tex;
	t_wall_params	params;

	ray = &game->rays[x];
	params.perp_dist = ray->distance * cos(ray->angle - player_angle_rad);
	if (params.perp_dist < 0.1)
		params.perp_dist = 0.1;
	params.proj_plane_dist = (SCREEN_WIDTH / 2.0) / tan((FOV_ANGLE * M_PI
				/ 180.0) / 2.0);
	params.wall_height = (int)((TILE_SIZE / params.perp_dist)
			* params.proj_plane_dist);
	params.draw_start = -params.wall_height / 2 + SCREEN_HEIGHT / 2;
	if (params.draw_start < 0)
		params.draw_start = 0;
	params.draw_end = params.wall_height / 2 + SCREEN_HEIGHT / 2;
	if (params.draw_end >= SCREEN_HEIGHT)
		params.draw_end = SCREEN_HEIGHT - 1;
	tex = select_wall_texture(game, ray->side, ray);
	params.x = x;
	params.tex_x = calculate_texture_x(tex, ray);
	draw_wall_column(game, &params, tex);
}

void	render_3d_walls(t_game *game)
{
	int		x;
	double	player_angle_rad;

	player_angle_rad = game->map->player.angle * M_PI / 180.0;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		draw_floor_and_ceiling(game, x);
		draw_wall_strip(game, x, player_angle_rad);
		x++;
	}
}
