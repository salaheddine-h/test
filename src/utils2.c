/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahosni <fahosni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:46:01 by salhali           #+#    #+#             */
/*   Updated: 2025/12/08 12:05:39 by fahosni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_atoi_helper(char *str, int *i, long *res)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (*res > 255 / 10)
			return (1);
		*res = ((*res) * 10) + (str[*i] - 48);
		(*i)++;
	}
	return (0);
}

long	ft_atomic_atoi(char *str)
{
	long	res;
	int		i;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (2147483650);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (2147483650);
	if (ft_atoi_helper(str, &i, &res))
		return (2147483650);
	if (str[i] != '\0')
		return (2147483650);
	return (res * sign);
}

bool	check_valid_map_help(char **map2d, int i, int j)
{
	if (map2d[i][j] == '0' || map2d[i][j] == 'D' || map2d[i][j] == 'W'
		|| map2d[i][j] == 'E' || map2d[i][j] == 'S' || map2d[i][j] == 'N')
	{
		if (i == 0 || j == 0 || !map2d[i + 1] || !map2d[i - 1] || !map2d[i][j
			+ 1] || !map2d[i][j - 1] || !map2d[i + 1][j] || !map2d[i - 1][j])
			return (false);
		if (map2d[i - 1][j] == ' ' || map2d[i + 1][j] == ' ' || map2d[i][j
			- 1] == ' ' || map2d[i][j + 1] == ' ')
			return (false);
	}
	return (true);
}
