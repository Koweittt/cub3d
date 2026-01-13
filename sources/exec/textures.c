/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 03:00:00 by narcisse          #+#    #+#             */
/*   Updated: 2026/01/12 17:47:20 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static int	load_texture(t_game *game, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image
		(game->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
	{
		write(2, "Error\nFailed to load texture\n", 31);
		return (-1);
	}
	tex->addr = mlx_get_data_addr
		(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
	return (0);
}

int	load_textures(t_game *game)
{
	if (load_texture(game, &game->tex_north, game->textures.north) == -1)
		return (-1);
	if (load_texture(game, &game->tex_south, game->textures.south) == -1)
		return (-1);
	if (load_texture(game, &game->tex_east, game->textures.east) == -1)
		return (-1);
	if (load_texture(game, &game->tex_west, game->textures.west) == -1)
		return (-1);
	return (0);
}
