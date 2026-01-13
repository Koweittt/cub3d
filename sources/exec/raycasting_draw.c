/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:00 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:17 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	get_texture_color(t_img *tex, int tex_x, int tex_y)
{
	char	*pixel;

	if (tex_x < 0 || tex_x >= tex->width || tex_y < 0 || tex_y >= tex->height)
		return (0);
	pixel = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

t_img	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&game->tex_east);
		else
			return (&game->tex_west);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (&game->tex_south);
		else
			return (&game->tex_north);
	}
}

static void	calculate_wall_params(t_game *game, t_ray *ray, int *draw_start,
		int *draw_end)
{
	int	line_height;

	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	*draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (*draw_end >= WIN_HEIGHT)
		*draw_end = WIN_HEIGHT - 1;
}

static void	draw_texture_column(t_game *game, t_ray *ray, int x,
		t_draw_params *params)
{
	int		y;
	int		tex_y;
	int		color;
	double	tex_pos;

	tex_pos = (params->draw_start - WIN_HEIGHT / 2 + params->line_height / 2)
		* params->step;
	y = params->draw_start;
	while (y < params->draw_end)
	{
		tex_y = (int)tex_pos & (params->texture->height - 1);
		tex_pos += params->step;
		color = get_texture_color(params->texture, params->tex_x, tex_y);
		put_pixel(&game->screen, x, y, color);
		y++;
	}
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	t_draw_params	params;
	double			wall_x;

	calculate_wall_params(game, ray, &params.draw_start, &params.draw_end);
	params.line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	params.texture = get_wall_texture(game, ray);
	params.tex_x = (int)(wall_x * (double)params.texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		params.tex_x = params.texture->width - params.tex_x - 1;
	params.step = 1.0 * params.texture->height / params.line_height;
	draw_texture_column(game, ray, x, &params);
}
