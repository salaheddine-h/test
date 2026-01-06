/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:32:58 by salhali           #+#    #+#             */
/*   Updated: 2026/01/06 17:35:03 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	start_parsing(int argc, char *argv, t_map *map)
{
	int	fd;

	(void)argc;
	if (argv == NULL || ft_strlen(argv) == '\0')
		error_print("No file here !", map);
	if (check_file_extension(argv) == false)
		error_print("Invalid file [.cub] !", map);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_print("File Not found", map);
	map_init(map);
	file_parser(fd, map);
	parse_textures(map);
	parser_colors(map);
	map_parser(fd, map);
	close(fd);
}
