/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:09:26 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 19:49:18 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static void	init_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->east = NULL;
	textures->west = NULL;
	textures->floor_color = NULL;
	textures->ceiling_color = NULL;
}

static void	init_map(t_map *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->player_y = 0;
	map->player_x = 0;
	map->player_dir = 'N';
}

void	init_game(t_game *game)
{
	game->win = NULL;
	game->mlx = NULL;
	game->key_w = 0;
	game->key_a = 0;
	game->key_s = 0;
	game->key_d = 0;
	game->key_left = 0;
	game->key_right = 0;
	init_textures(&game->textures);
	init_map(&game->map);
}

int	check_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	check_extension_xpm(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".xpm", 4) != 0)
		return (0);
	return (1);
}
