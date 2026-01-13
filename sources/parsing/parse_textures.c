/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:00 by abignals          #+#    #+#             */
/*   Updated: 2026/01/13 16:40:18 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"
#include "../../includes/Libft/libft.h"

static int	parse_path(char *line, t_game *game, char *temp)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && temp)
		game->textures.north = temp;
	else if (ft_strncmp(line, "SO ", 3) == 0 && temp)
		game->textures.south = temp;
	else if (ft_strncmp(line, "EA ", 3) == 0 && temp)
		game->textures.east = temp;
	else if (ft_strncmp(line, "WE ", 3) == 0 && temp)
		game->textures.west = temp;
	else
		return (0);
	return (1);
}

static int	parse_color(char *line, t_game *game, t_rgb *color)
{
	if (ft_strncmp(line, "F ", 2) == 0 && color)
		game->textures.floor_color = color;
	else if (ft_strncmp(line, "C ", 2) == 0 && color)
		game->textures.ceiling_color = color;
	else
		return (0);
	return (1);
}

static int	parse_texture_line(char *line, t_game *game)
{
	while (*line && (*line == 32 || (*line >= 9 && *line <= 13)))
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "WE ", 3) == 0)
		return (parse_path(line, game, extract_line(line, 3)));
	else if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (parse_color(line, game, fill_color(line, 2)));
	return (0);
}

static int	skip_empty_line(char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
		return (1);
	return (0);
}

int	parse_textures(int fd, t_game *game)
{
	char	*line;
	int		count;

	count = 0;
	while (count < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (skip_empty_line(line))
		{
			free(line);
			continue ;
		}
		if (parse_texture_line(line, game))
			count++;
		free(line);
	}
	return (validate_textures(&game->textures));
}
