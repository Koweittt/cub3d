/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narcisse <narcisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:00:00 by narcisse          #+#    #+#             */
/*   Updated: 2026/01/11 01:37:04 by narcisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static void	free_textures_mlx(t_game *game)
{
	if (game->tex_north.img)
		mlx_destroy_image(game->mlx, game->tex_north.img);
	if (game->tex_south.img)
		mlx_destroy_image(game->mlx, game->tex_south.img);
	if (game->tex_east.img)
		mlx_destroy_image(game->mlx, game->tex_east.img);
	if (game->tex_west.img)
		mlx_destroy_image(game->mlx, game->tex_west.img);
}

static void	free_textures_paths(t_game *game)
{
	if (game->textures.north)
		free(game->textures.north);
	if (game->textures.south)
		free(game->textures.south);
	if (game->textures.east)
		free(game->textures.east);
	if (game->textures.west)
		free(game->textures.west);
}

static void	free_colors(t_game *game)
{
	if (game->textures.floor_color)
		free(game->textures.floor_color);
	if (game->textures.ceiling_color)
		free(game->textures.ceiling_color);
}

void	free_game(t_game *game)
{
	if (game->mlx)
	{
		free_textures_mlx(game);
		if (game->screen.img)
			mlx_destroy_image(game->mlx, game->screen.img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_textures_paths(game);
	free_colors(game);
	if (game->map.map)
		free_map(game->map.map);
}
