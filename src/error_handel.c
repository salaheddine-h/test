/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:38:18 by salhali           #+#    #+#             */
/*   Updated: 2026/01/06 21:00:41 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void error_print(char *msg, t_map *map)
{
    (void)map;
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    ft_free_all();
    exit(1);
}
