/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:00:00 by salhali           #+#    #+#             */
/*   Updated: 2025/12/08 12:01:35 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

unsigned int	get_pixel_from_texture(t_texture *tex, int tex_x, int tex_y)
{
	char	*pixel_addr;

	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	pixel_addr = tex->addr + (tex_y * tex->line_length + tex_x * (tex->bpp
				/ 8));
	return (*(unsigned int *)pixel_addr);
}

int	calculate_texture_x(t_texture *tex, t_ray *ray)
{
	int		tex_x;
	double	wall_x;

	wall_x = calculate_wall_x(ray, ray->side);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->raydirx > 0) || (ray->side == 1
			&& ray->raydiry < 0))
		tex_x = tex->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	return (tex_x);
}

t_texture	*select_wall_texture(t_game *game, int side, t_ray *ray)
{
	if (side == 0)
	{
		if (ray->raydirx > 0)
			return (&game->wall_texture[3]);
		else
			return (&game->wall_texture[2]);
	}
	else
	{
		if (ray->raydiry > 0)
			return (&game->wall_texture[1]);
		else
			return (&game->wall_texture[0]);
	}
}

double	calculate_wall_x(t_ray *ray, int side)
{
	double	wall_x;

	if (side == 0)
		wall_x = ray->hit_y / TILE_SIZE;
	else
		wall_x = ray->hit_x / TILE_SIZE;
	wall_x -= floor(wall_x);
	return (wall_x);
}

void	draw_wall_column(t_game *game, t_wall_params *params, t_texture *tex)
{
	double			step;
	double			tex_pos;
	int				y;
	int				tex_y;
	unsigned int	color;

	step = (double)tex->height / (double)params->wall_height;
	tex_pos = (params->draw_start - SCREEN_HEIGHT / 2.0 + params->wall_height
			/ 2.0) * step;
	y = params->draw_start;
	while (y <= params->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		color = get_pixel_from_texture(tex, params->tex_x, tex_y);
		put_pixel(game, params->x, y, color);
		tex_pos += step;
		y++;
	}
}
