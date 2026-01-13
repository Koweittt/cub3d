/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:00 by abignals          #+#    #+#             */
/*   Updated: 2026/01/13 16:34:45 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static char	*trim_whitespace(char *str)
{
	char	*end;
	char	*trimmed;
	int		len;

	if (!str)
		return (NULL);
	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'
			|| *end == '\r' || *end == '\v' || *end == '\f'))
		end--;
	len = end - str + 1;
	trimmed = malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, str, len);
	trimmed[len] = '\0';
	return (trimmed);
}

char	*extract_line(char *line, int i)
{
	char	*ret;
	char	*trimmed;
	int		j;
	int		k;

	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	j = i;
	while (line[i] && line[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * (i - j + 1));
	if (!ret)
		return (NULL);
	k = 0;
	while (j < i)
	{
		ret[k] = line[j];
		k++;
		j++;
	}
	ret[k] = '\0';
	trimmed = trim_whitespace(ret);
	free(ret);
	return (trimmed);
}

char	**ft_realloc_map(char **map, int new_size)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (new_size + 1));
	if (!new_map)
		return (NULL);
	while (map && map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	while (i < new_size)
	{
		new_map[i] = NULL;
		i++;
	}
	new_map[new_size] = NULL;
	if (map)
		free(map);
	return (new_map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != 32 && !(line[i] >= 9 && line[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}
