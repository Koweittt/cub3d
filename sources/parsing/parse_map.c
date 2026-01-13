/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:00 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:17 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"
#include "../../includes/Libft/libft.h"

static char	*skip_to_map(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_empty_line(line))
		{
			free(line);
			continue ;
		}
		break ;
	}
	return (line);
}

static int	add_line_to_map(t_game *game, char *line, int height)
{
	char	**temp;
	int		len;

	temp = ft_realloc_map(game->map.map, height + 1);
	if (!temp)
		return (-1);
	game->map.map = temp;
	game->map.map[height] = line;
	len = ft_strlen(line);
	if (len > game->map.width)
		game->map.width = len;
	return (0);
}

int	parse_map(int fd, t_game *game)
{
	char	*line;
	int		height;

	height = 0;
	game->map.map = NULL;
	line = skip_to_map(fd);
	while (line)
	{
		if (add_line_to_map(game, line, height) == -1)
			return (-1);
		height++;
		line = get_next_line(fd);
	}
	game->map.height = height;
	return (0);
}
