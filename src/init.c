/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:09:26 by abignals          #+#    #+#             */
/*   Updated: 2025/12/19 20:15:28 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cub3d.h"

static void	init_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->east = NULL;
	textures->west = NULL;
	textures->floor_color = -1;
	textures->ceiling_color = -1;
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
	init_textures(&game->textures);
	init_map(&game->map);
}