/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:00 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:17 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	game_loop(t_game *game)
{
	if (!game || !game->mlx || !game->win)
		return (0);
	move_player(game);
	render_frame(game);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_W)
		game->key_w = 1;
	if (keycode == KEY_A)
		game->key_a = 1;
	if (keycode == KEY_S)
		game->key_s = 1;
	if (keycode == KEY_D)
		game->key_d = 1;
	if (keycode == KEY_LEFT)
		game->key_left = 1;
	if (keycode == KEY_RIGHT)
		game->key_right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key_w = 0;
	if (keycode == KEY_A)
		game->key_a = 0;
	if (keycode == KEY_S)
		game->key_s = 0;
	if (keycode == KEY_D)
		game->key_d = 0;
	if (keycode == KEY_LEFT)
		game->key_left = 0;
	if (keycode == KEY_RIGHT)
		game->key_right = 0;
	return (0);
}
