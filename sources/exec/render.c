/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:30:00 by narcisse          #+#    #+#             */
/*   Updated: 2026/01/12 18:59:59 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

inline int	rgb_to_int(t_rgb *rgb)
{
	return ((rgb->r << 16) | (rgb->g << 8) | rgb->b);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	draw_ceiling_floor_line(t_game *game, int y,
		int ceiling, int floor)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		if (y < WIN_HEIGHT / 2)
			put_pixel(&game->screen, x, y, ceiling);
		else
			put_pixel(&game->screen, x, y, floor);
		x++;
	}
}

void	render_background(t_game *game)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	if (!game->textures.ceiling_color || !game->textures.floor_color)
		return ;
	ceiling_color = rgb_to_int(game->textures.ceiling_color);
	floor_color = rgb_to_int(game->textures.floor_color);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		draw_ceiling_floor_line(game, y, ceiling_color, floor_color);
		y++;
	}
}

void	render_frame(t_game *game)
{
	render_background(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}
