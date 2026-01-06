/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:37:36 by salhali           #+#    #+#             */
/*   Updated: 2026/01/06 18:15:13 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_substr_plus(char *string)
{
	int		i;
	char	*str;
	char	*r_str;

	i = 0;
	if (!string)
		return (NULL);
	while (string[i] && ft_isspace(string[i]))
		i++;
	str = ft_substr(string, i, ft_strlen(string));
	free(string);
	r_str = ft_strtrim1(str, " ");
	free(str);
	return (r_str);
}

bool	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

void	parse_textures(t_map *map)
{
	char	*tmp;

	tmp = map->north_texture;
	map->north_texture = ft_substr_plus(tmp);
	tmp = map->south_texture;
	map->south_texture = ft_substr_plus(tmp);
	tmp = map->west_texture;
	map->west_texture = ft_substr_plus(tmp);
	tmp = map->east_texture;
	map->east_texture = ft_substr_plus(tmp);
	if (!check_path(map->north_texture) || !check_path(map->south_texture)
		|| !check_path(map->west_texture) || !check_path(map->east_texture))
	{
		ft_free_all();
		free(map->north_texture);
		free(map->south_texture);
		free(map->east_texture);
		free(map->west_texture);
		error_print("Invalid path\n", map);
	}
}

int	ft_strcmp(const char *dest, const char *src)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (src[i] != '\0' && dest[i] != '\0')
	{
		if (src[i] != dest[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (ptr1[i] - ptr2[i]);
}

bool	check_map(char *map)
{
	if (map == NULL || ft_strlen(map) == 0)
		return (false);
	if (!check_newline(map))
		return (false);
	if (!check_valid_chars(map))
		return (false);
	if (!check_valid_map(map))
		return (false);
	return (true);
}
