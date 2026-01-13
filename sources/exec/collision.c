/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:00 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:17 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	check_collision(t_game *game, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map_y < 0 || map_y >= game->map.height)
		return (1);
	if (!game->map.map || !game->map.map[map_y])
		return (1);
	if (map_x < 0 || map_x >= (int)ft_strlen(game->map.map[map_y]))
		return (1);
	if (game->map.map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos
		(angle) - game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin
		(angle) + game->player.dir_y * cos(angle);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos
		(angle) - game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin
		(angle) + game->player.plane_y * cos(angle);
}
