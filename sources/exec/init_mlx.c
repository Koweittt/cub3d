/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:00:00 by narcisse          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:17 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

static int	create_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		write(2, "Error\nWindow creation failed\n", 31);
		return (-1);
	}
	return (0);
}

static int	create_image(t_game *game)
{
	game->screen.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->screen.img)
	{
		write(2, "Error\nImage creation failed\n", 30);
		return (-1);
	}
	game->screen.addr = mlx_get_data_addr(game->screen.img, &game->screen.bpp,
			&game->screen.line_len, &game->screen.endian);
	game->screen.width = WIN_WIDTH;
	game->screen.height = WIN_HEIGHT;
	return (0);
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 3, 1L << 1, handle_keyrelease, game);
	mlx_loop_hook(game->mlx, game_loop, game);
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error\nMLX initialization failed\n", 33);
		return (-1);
	}
	if (create_window(game) == -1)
		return (-1);
	if (create_image(game) == -1)
		return (-1);
	setup_hooks(game);
	return (0);
}
