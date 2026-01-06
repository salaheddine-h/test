/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:05:26 by salhali           #+#    #+#             */
/*   Updated: 2025/12/07 18:13:14 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_strdup2(const char *s)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	save_textures(char *line, t_map *map)
{
	if (!line || !ft_strlen(line))
		return ;
	if (ft_strnstr(line, "NO ", 3))
	{
		if (!map->north_texture)
		{
			map->north_texture = ft_strdup(line);
			// free(line);
		}
		else
			error_print("Duplicate NO texture");
	}
	else if (ft_strnstr(line, "SO ", 3))
	{
		if (!map->south_texture)
		{
			map->south_texture = ft_strdup(line);
			// free(line);
		}
		else
			error_print("Duplicate SO texture");
	}
	else if (ft_strnstr(line, "WE ", 3) || ft_strnstr(line, "EA ", 3))
		save_texture_helper(line, map);
	else
		error_print("Invalid texture");
}

void	save_texture_helper(char *line, t_map *map)
{
	if (ft_strnstr(line, "WE ", 3))
	{
		if (!map->west_texture)
		{
			map->west_texture = ft_strdup(line);
			// free(line);
		}
		else
			error_print("Duplicate WE texture");
	}
	else if (ft_strnstr(line, "EA ", 3))
	{
		if (!map->east_texture)
		{
			map->east_texture = ft_strdup(line);
			// free(line);
		}
		else
			error_print("Duplicate EA texture");
	}
}

void	save_colors(char *line, t_map *map)
{
	// printf("line = %s\n", line);
	if (!line || !ft_strlen(line))
		return ;
	if (ft_strnstr(line, "F ", 2))
	{
		if (!map->floor_color)
			map->floor_color = ft_strdup2(line);
		else
			error_print("Duplicate F texture");
	}
	else if (ft_strnstr(line, "C ", 2))
	{
		if (!map->ceiling_color)
			map->ceiling_color = ft_strdup2(line);
		else
			error_print("Duplicate ceiling color");
	}
	else
		error_print("Invalid color");
}

void	file_parser(int fd, t_map *map)
{
	char	*line;
	char	*real_line;

	while (1)
	{
		real_line = get_next_line(fd);
		line = ft_strtrim(real_line, "\n");
		free(real_line);
		if (!line)
			break ;
		if (!map->north_texture || !map->south_texture || !map->west_texture
			|| !map->east_texture)
			save_textures(line, map);
		else if (!map->floor_color || !map->ceiling_color)
			save_colors(line, map);
		free(line);
		line = NULL;
		if (map->north_texture && map->south_texture && map->west_texture
			&& map->east_texture && map->floor_color && map->ceiling_color)
			break ;
	}
	if (!map->north_texture || !map->south_texture || !map->west_texture
		|| !map->east_texture || !map->floor_color || !map->ceiling_color)
		error_print("Missing Textures/Color");
}
