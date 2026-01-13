/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:40:12 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 19:53:42 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	validate_map(t_map *map)
{
	if (find_player(map) == -1)
		return (-1);
	if (check_valid_chars(map) == -1)
		return (-1);
	if (is_map_closed(map) == -1)
		return (-1);
	return (0);
}

static int	check_texture_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	if (check_extension_xpm(path) == 0)
		return (-1);
	return (0);
}

int	validate_textures(t_textures *tex)
{
	if (check_texture_file(tex->north) == -1)
		return (-1);
	if (check_texture_file(tex->south) == -1)
		return (-1);
	if (check_texture_file(tex->east) == -1)
		return (-1);
	if (check_texture_file(tex->west) == -1)
		return (-1);
	if (!tex->ceiling_color || verif_color(tex->ceiling_color) == -1)
		return (-1);
	if (!tex->floor_color || verif_color(tex->floor_color) == -1)
		return (-1);
	return (0);
}

int	verif_color(t_rgb *rgb)
{
	if (rgb->r == -1)
		return (-1);
	if (rgb->g == -1)
		return (-1);
	if (rgb->b == -1)
		return (-1);
	return (1);
}
