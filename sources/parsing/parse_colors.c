/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:00 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 19:11:55 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

t_rgb	*init_color(void)
{
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		return (NULL);
	rgb->r = -1;
	rgb->g = -1;
	rgb->b = -1;
	return (rgb);
}

static void	set_rgb_component(t_rgb *rgb, int j, char *line, int i)
{
	if (j == 0)
		rgb->r = extract_line_atoi(line, i);
	else if (j == 1)
		rgb->g = extract_line_atoi(line, i);
	else if (j == 2)
		rgb->b = extract_line_atoi(line, i);
}

t_rgb	*fill_color(char *line, int i)
{
	t_rgb	*rgb;
	int		j;

	rgb = init_color();
	if (!rgb)
		return (NULL);
	j = 0;
	while (line[i] != '\n' && line[i] && j < 3)
	{
		if (is_num(line[i]))
		{
			set_rgb_component(rgb, j, line, i);
			while (line[i] && is_num(line[i]))
				i++;
			j++;
		}
		else
			i++;
	}
	if (verif_color(rgb) == -1)
	{
		free(rgb);
		return (NULL);
	}
	return (rgb);
}
