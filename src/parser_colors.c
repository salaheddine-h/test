/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:39:21 by salhali           #+#    #+#             */
/*   Updated: 2026/01/06 17:26:15 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

bool	check_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (false);
	return (true);
}

void	parse_rgb(t_map *map)
{
	char	**split;
	int		i;

	split = ft_split(map->floor_color, ',');
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		error_print("Invalid color format", map);
	map->floor_rgb.r = ft_atomic_atoi(split[0]);
	map->floor_rgb.g = ft_atomic_atoi(split[1]);
	map->floor_rgb.b = ft_atomic_atoi(split[2]);
	free_split(split);
	split = ft_split(map->ceiling_color, ',');
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		error_print("Invalid color format", map);
	map->ceiling_rgb.r = ft_atomic_atoi(split[0]);
	map->ceiling_rgb.g = ft_atomic_atoi(split[1]);
	map->ceiling_rgb.b = ft_atomic_atoi(split[2]);
	free_split(split);
}

bool	check_rgb(t_rgb rgb)
{
	if (rgb.r < 0 || rgb.r > 255 || rgb.g < 0 || rgb.g > 255 || rgb.b < 0
		|| rgb.b > 255)
		return (false);
	return (true);
}

void	parser_colors(t_map *map)
{
	map->floor_color = ft_substr_plus(map->floor_color);
	map->ceiling_color = ft_substr_plus(map->ceiling_color);
	if (!check_comma(map->floor_color) || !check_comma(map->ceiling_color))
	{
		free(map->floor_color);
		free(map->ceiling_color);
		free(map->north_texture);
		free(map->south_texture);
		free(map->west_texture);
		free(map->east_texture);
		ft_free_all();
		error_print("Invalid color formatttttttttttttttttt", map);
	}
	parse_rgb(map);
	if (!check_rgb(map->floor_rgb)
		|| !check_rgb(map->ceiling_rgb))
	{
				free(map->north_texture);
		free(map->south_texture);
		free(map->west_texture);
		free(map->east_texture);
		free(map->floor_color);
		free(map->ceiling_color);
		ft_free_all();
		error_print("Invalid color rangeee", map);
	}
}
