/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:00:00 by narcisse          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:17 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static void	move_forward_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	if (game->key_w)
	{
		new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
		new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
		if (!check_collision(game, new_x, game->player.pos_y))
			game->player.pos_x = new_x;
		if (!check_collision(game, game->player.pos_x, new_y))
			game->player.pos_y = new_y;
	}
	if (game->key_s)
	{
		new_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
		new_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
		if (!check_collision(game, new_x, game->player.pos_y))
			game->player.pos_x = new_x;
		if (!check_collision(game, game->player.pos_x, new_y))
			game->player.pos_y = new_y;
	}
}

static void	move_strafe(t_game *game)
{
	double	new_x;
	double	new_y;

	if (game->key_a)
	{
		new_x = game->player.pos_x - game->player.plane_x * MOVE_SPEED;
		new_y = game->player.pos_y - game->player.plane_y * MOVE_SPEED;
		if (!check_collision(game, new_x, game->player.pos_y))
			game->player.pos_x = new_x;
		if (!check_collision(game, game->player.pos_x, new_y))
			game->player.pos_y = new_y;
	}
	if (game->key_d)
	{
		new_x = game->player.pos_x + game->player.plane_x * MOVE_SPEED;
		new_y = game->player.pos_y + game->player.plane_y * MOVE_SPEED;
		if (!check_collision(game, new_x, game->player.pos_y))
			game->player.pos_x = new_x;
		if (!check_collision(game, game->player.pos_x, new_y))
			game->player.pos_y = new_y;
	}
}

static void	rotate_arrows(t_game *game)
{
	if (game->key_left)
		rotate_player(game, -ROT_SPEED);
	if (game->key_right)
		rotate_player(game, ROT_SPEED);
}

void	move_player(t_game *game)
{
	move_forward_backward(game);
	move_strafe(game);
	rotate_arrows(game);
}
