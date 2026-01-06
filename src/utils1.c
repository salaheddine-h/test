/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:45:01 by salhali           #+#    #+#             */
/*   Updated: 2026/01/06 21:39:04 by salhali          ###   ########.fr       */
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

char *ft_strtrim1(char const *s1, char const *set)
{
    char    *str;
    size_t  start;
    size_t  end;
    size_t  i;

    if (!s1 || !set)
        return (NULL);

    end = ft_strlen(s1);
    start = 0;

    while (end > start && is_set(s1[end - 1], set))
        end--;
    while (s1[start] && is_set(s1[start], set))
        start++;

    if (start >= end)
    {
        str = ft_malloc(1);
        str[0] = '\0';
        return (str);
    }

    str = ft_malloc(end - start + 1);
    i = 0;
    while (start < end)
        str[i++] = s1[start++];
    str[i] = '\0';
    return (str);
}

