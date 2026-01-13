/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:00 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:17 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static int	check_hit_bounds(t_game *game, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_y >= game->map.height)
		return (1);
	if (ray->map_x < 0 || ray->map_x >= (int)
		ft_strlen(game->map.map[ray->map_y]))
		return (1);
	if (game->map.map[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}

void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (check_hit_bounds(game, ray))
		{
			ray->hit = 1;
			break ;
		}
	}
}
