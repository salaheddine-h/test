/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:38:18 by salhali           #+#    #+#             */
/*   Updated: 2025/09/01 20:58:17 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	error_print(char *str)
{
	printf("\nError : ");
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}
