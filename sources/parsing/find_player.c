/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trambure <trambure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:00 by abignals          #+#    #+#             */
/*   Updated: 2026/01/13 15:57:43 by trambure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

static int	check_player_count(int count, t_map *map, int i, int j)
{
	if (count == 1)
	{
		write(2, "Error\nToo many players in map\n", 31);
		return (-1);
	}
	map->player_x = j;
	map->player_y = i;
	map->player_dir = map->map[i][j];
	return (0);
}

static int	process_player_cell(t_map *map, int i, int j, int *count)
{
	if (is_player_char(map->map[i][j]))
	{
		if (check_player_count(*count, map, i, j) == -1)
			return (-1);
		(*count)++;
	}
	return (0);
}

static int	scan_row_for_player(t_map *map, int i, int *count)
{
	int	j;

	j = 0;
	while (map->map[i][j])
	{
		if (process_player_cell(map, i, j, count) == -1)
			return (-1);
		j++;
	}
	return (0);
}

int	find_player(t_map *map)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!map->map)
		return (-1);
	while (map->map[i])
	{
		if (scan_row_for_player(map, i, &count) == -1)
			return (-1);
		i++;
	}
	if (count == 0)
	{
		write(2, "Error\nNo player found in map\n", 30);
		return (-1);
	}
	return (0);
}
