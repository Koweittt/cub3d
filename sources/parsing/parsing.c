/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:05:37 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 19:20:49 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"
#include "../../includes/Libft/libft.h"

static int	open_and_validate_file(char *filename)
{
	int	fd;

	if (!check_extension(filename))
	{
		write(2, "Error\nInvalid file extension\n", 30);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		write(2, "Error\nCannot open file\n", 24);
	return (fd);
}

static int	parse_file_content(int fd, t_game *game)
{
	if (parse_textures(fd, game) == -1)
	{
		write(2, "Error\nInvalid texture configuration\n", 37);
		return (-1);
	}
	if (parse_map(fd, game) == -1)
	{
		write(2, "Error\nInvalid map\n", 19);
		return (-1);
	}
	return (0);
}

int	parse_file(char *filename, t_game *game)
{
	int		fd;

	fd = open_and_validate_file(filename);
	if (fd == -1)
		return (-1);
	if (parse_file_content(fd, game) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (validate_map(&game->map) == -1)
	{
		write(2, "Error\nMap validation failed\n", 29);
		return (-1);
	}
	return (0);
}
