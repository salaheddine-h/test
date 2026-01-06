/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:00:43 by fahosni           #+#    #+#             */
/*   Updated: 2025/12/08 12:00:44 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	handle_movement(void)
{
	int	update;

	update = 0;
	if (g_game()->keys.w)
	{
		ft_up();
		update = 1;
	}
	if (g_game()->keys.s)
	{
		ft_down();
		update = 1;
	}
	if (g_game()->keys.d)
	{
		ft_right();
		update = 1;
	}
	if (g_game()->keys.a)
	{
		ft_left();
		update = 1;
	}
	return (update);
}

static int	handle_rotation(void)
{
	int	update;

	update = 0;
	if (g_game()->keys.left)
	{
		g_game()->map->player.angle -= ROT_SPEED * 180.0 / M_PI;
		update = 1;
	}
	if (g_game()->keys.right)
	{
		g_game()->map->player.angle += ROT_SPEED * 180.0 / M_PI;
		update = 1;
	}
	return (update);
}

int	moves(void)
{
	int	update;

	update = handle_movement();
	update |= handle_rotation();
	if (update)
		update_game(g_game());
	return (0);
}
