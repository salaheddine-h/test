/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:41:53 by salhali           #+#    #+#             */
/*   Updated: 2025/12/07 18:58:29 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

bool	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	set_player_angle(t_map *map)
{
	if (map->player.dir == 'N')
		map->player.angle = 270;
	else if (map->player.dir == 'S')
		map->player.angle = 90;
	else if (map->player.dir == 'E')
		map->player.angle = 0;
	else
		map->player.angle = 180;
}

void	init_player_position(t_map *map, int i, int j)
{
	if (map->player.dir)
		error_print("Duplicate player");
	map->player.dir = map->map[i][j];
	map->player.x = j * TILE_SIZE + TILE_SIZE / 2;
	map->player.y = i * TILE_SIZE + TILE_SIZE / 2;
	set_player_angle(map);
	map->map[i][j] = '0';
}

void	save_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_player_char(map->map[i][j]))
				init_player_position(map, i, j);
			j++;
		}
		i++;
	}
	if (!map->player.dir)
		error_print("Player not found");
}

void	map_parser(int fd, t_map *map)
{
	char	*line;
	char	*map1d;

	map1d = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map1d = ft_strjoin1(map1d, line);
		if (ft_strcmp(line, "\n"))
			map->map_height++;
		free(line);
	}
	if (check_map(map1d) == false)
		error_print("Invalid map\n");
	map->map = ft_split(map1d, '\n');
	save_player(map);
	free(map1d);
}
