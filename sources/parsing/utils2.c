/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:07:52 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:17 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	extract_line_atoi(char *line, int i)
{
	int	j;
	int	result;

	j = i;
	result = 0;
	while (line[j] && is_num(line[j]))
	{
		result = result * 10 + (line[j] - '0');
		j++;
	}
	return (result);
}

static int	flood_fill_recursive(char **map, t_map *values, int x, int y)
{
	t_map	temp;

	temp.player_y = y - 1;
	temp.player_x = x;
	temp.height = values->height;
	if (flood_fill(map, &temp) == -1)
		return (-1);
	temp.player_y = y + 1;
	if (flood_fill(map, &temp) == -1)
		return (-1);
	temp.player_x = x - 1;
	temp.player_y = y;
	if (flood_fill(map, &temp) == -1)
		return (-1);
	temp.player_x = x + 1;
	if (flood_fill(map, &temp) == -1)
		return (-1);
	return (0);
}

int	flood_fill(char **map, t_map *values)
{
	int		x;
	int		y;

	y = values->player_y;
	x = values->player_x;
	if (x < 0 || y < 0 || y >= values->height || x >= (int)ft_strlen(map[y]))
		return (-1);
	if (map[y][x] == ' ' || map[y][x] == '\n')
		return (-1);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	map[y][x] = 'X';
	return (flood_fill_recursive(map, values, x, y));
}
