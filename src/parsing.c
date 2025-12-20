/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:05:37 by abignals          #+#    #+#             */
/*   Updated: 2025/12/19 18:29:06 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cub3d.h"

static int	check_extension(char *filename)
{
	int len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strcmp(filename + len - 4, ".cub") != 0)
		return (0);
	return (1);
}

int parse_file(char *filename, t_game *game)
{
	int		fd;

	if (!check_extension(filename))
		return (fprintf(stderr, "Error\nInvalid file extension\n") -1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (fprintf(stderr, "Error\nCannot open file\n") -1);
	if (parse_textures(fd, game) == -1)
	{
		close(fd);
		return (fprintf(stderr, "Error\nInvalid texture configuration\n") -1);
	}
	if (parse_map(fd, game) == -1)
	{
		close(fd);
		free_textures(&game->textures);
		return (fprintf(stderr, "Error\nInvalid map\n"), -1);
	}
	close(fd);
	if (validate_map(&game->map) == -1)
	{
		free_game(game);
		return (fprintf(stderr, "Error\nMap validation failed"), -1);
	}
}

int parse_textures(int fd, t_game *game)
{
	
}

int parse_map(int fd, t_game *game)
{
	//Read et trouver la map
}

int validate_map(t_map *map)
{
	//Valider la map (flood fill plus verif ig)
	//Peux se trouver dans parse_map
}

int validate_textures(t_textures *tex)
{
	//Ouvrir et verifier que les textures sont utilisables
	//Peux se trouver dans parse_textures	
}