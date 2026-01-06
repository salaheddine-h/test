/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:38:18 by salhali           #+#    #+#             */
/*   Updated: 2026/01/06 17:59:27 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// void	error_print(char *str)
// {
// 	printf("\nError : ");
// 	printf("%s\n", str);
// 	exit(EXIT_FAILURE);
// }
void error_print(char *msg, t_map *map)
{
    printf("Error : %s\n", msg);
    free_map(map);
    // free_all_allocations(); // if you use ft_malloc
    exit(1);
}
