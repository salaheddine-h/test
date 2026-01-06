/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:45:01 by salhali           #+#    #+#             */
/*   Updated: 2025/12/07 18:41:11 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

bool	check_newline(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] == '\n')
		i++;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	check_valid_chars(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != ' ' && map[i] != 'D' && map[i] != '\n' && map[i] != '1'
			&& map[i] != '0' && map[i] != 'N' && map[i] != 'S' && map[i] != 'W'
			&& map[i] != 'E')
			return (false);
		i++;
	}
	return (true);
}

bool	check_valid_map(char *map)
{
	char	**map2d;
	int		i;
	int		j;

	map2d = ft_split(map, '\n');
	i = 0;
	while (map2d[i])
	{
		j = 0;
		if (is_all_whitespace(map2d[i]))
			return (free_split(map2d), false);
		while (map2d[i][j])
		{
			if (!check_valid_map_help(map2d, i, j))
				return (free_split(map2d), false);
			j++;
		}
		i++;
	}
	free_split(map2d);
	return (true);
}

bool	is_all_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}
