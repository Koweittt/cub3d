/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:45:00 by narcisse          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:17 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static void	set_player_ns(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
}

static void	set_player_ew(t_game *game, char dir)
{
	if (dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

static void	set_player_direction(t_game *game, char dir)
{
	if (dir == 'N' || dir == 'S')
		set_player_ns(game, dir);
	else if (dir == 'E' || dir == 'W')
		set_player_ew(game, dir);
}

void	init_player(t_game *game)
{
	game->player.pos_x = game->map.player_x + 0.5;
	game->player.pos_y = game->map.player_y + 0.5;
	set_player_direction(game, game->map.player_dir);
}
