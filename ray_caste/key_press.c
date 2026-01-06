/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:44:05 by salhali           #+#    #+#             */
/*   Updated: 2025/12/08 11:58:32 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	key_press(int keycode, t_game *g)
{
	if (keycode == 65307)
	{
		close_window(g);
		exit(0);
	}
	else if (keycode == 119)
		g->keys.w = 1;
	else if (keycode == 115)
		g->keys.s = 1;
	else if (keycode == 97)
		g->keys.a = 1;
	else if (keycode == 100)
		g->keys.d = 1;
	else if (keycode == 65361)
		g->keys.left = 1;
	else if (keycode == 65363)
		g->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_game *g)
{
	if (keycode == 119)
		g->keys.w = 0;
	else if (keycode == 115)
		g->keys.s = 0;
	else if (keycode == 97)
		g->keys.a = 0;
	else if (keycode == 100)
		g->keys.d = 0;
	else if (keycode == 65361)
		g->keys.left = 0;
	else if (keycode == 65363)
		g->keys.right = 0;
	return (0);
}
