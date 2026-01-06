/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:00:48 by fahosni           #+#    #+#             */
/*   Updated: 2025/12/08 12:00:49 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_up(void)
{
	t_game	*g;
	double	rad;
	double	nextx;
	double	nexty;

	g = g_game();
	rad = g->map->player.angle * M_PI / 180.0;
	nextx = g->map->player.x + cos(rad) * MOVE_SPEED;
	nexty = g->map->player.y + sin(rad) * MOVE_SPEED;
	if (!is_wall(g->map, nextx, g->map->player.y))
		g->map->player.x = nextx;
	if (!is_wall(g->map, g->map->player.x, nexty))
		g->map->player.y = nexty;
}

void	ft_down(void)
{
	t_game	*g;
	double	rad;
	double	nextx;
	double	nexty;

	g = g_game();
	rad = g->map->player.angle * M_PI / 180.0;
	nextx = g->map->player.x - cos(rad) * MOVE_SPEED;
	nexty = g->map->player.y - sin(rad) * MOVE_SPEED;
	if (!is_wall(g->map, nextx, g->map->player.y))
		g->map->player.x = nextx;
	if (!is_wall(g->map, g->map->player.x, nexty))
		g->map->player.y = nexty;
}

void	ft_right(void)
{
	t_game	*g;
	double	rad;
	double	nextx;
	double	nexty;

	g = g_game();
	rad = (g->map->player.angle * M_PI / 180.0) + M_PI / 2.0;
	nextx = g->map->player.x + cos(rad) * MOVE_SPEED;
	nexty = g->map->player.y + sin(rad) * MOVE_SPEED;
	if (!is_wall(g->map, nextx, g->map->player.y))
		g->map->player.x = nextx;
	if (!is_wall(g->map, g->map->player.x, nexty))
		g->map->player.y = nexty;
}

void	ft_left(void)
{
	t_game	*g;
	double	rad;
	double	nextx;
	double	nexty;

	g = g_game();
	rad = (g->map->player.angle * M_PI / 180.0) - M_PI / 2.0;
	nextx = g->map->player.x + cos(rad) * MOVE_SPEED;
	nexty = g->map->player.y + sin(rad) * MOVE_SPEED;
	if (!is_wall(g->map, nextx, g->map->player.y))
		g->map->player.x = nextx;
	if (!is_wall(g->map, g->map->player.x, nexty))
		g->map->player.y = nexty;
}
