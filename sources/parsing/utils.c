/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trambure <trambure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:30:43 by abignals          #+#    #+#             */
/*   Updated: 2026/01/13 15:58:58 by trambure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static char	*copy_map_line(char *line)
{
	char	*copy;
	int		j;

	copy = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!copy)
		return (NULL);
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		copy[j] = line[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = copy_map_line(map[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	is_map_closed(t_map *map)
{
	char	**copy;

	copy = copy_map(map->map, map->height);
	if (!copy)
	{
		write(2, "Error\nChecking the map\n", 24);
		return (-1);
	}
	if (flood_fill(copy, map) == -1)
	{
		free_map(copy);
		write(2, "Error\nMap is not closed\n", 25);
		return (-1);
	}
	free_map(copy);
	return (0);
}

int	check_valid_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != 'N' && map->map[i][j] != 'S' &&
				map->map[i][j] != 'E' && map->map[i][j] != 'W' &&
				map->map[i][j] != '0' && map->map[i][j] != '1' &&
				map->map[i][j] != ' ' && map->map[i][j] != '\n')
			{
				write(2, "Error\nInvalid character in map\n", 33);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
