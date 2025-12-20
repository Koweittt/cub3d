/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:58:21 by abignals          #+#    #+#             */
/*   Updated: 2025/12/17 20:04:58 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor_color;
	int		ceiling_color;
}	t_textures;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player_y;
	int		player_x;
	char	player_dir;
}	t_map;

typedef struct s_game
{
	t_textures	textures;
	t_map		map;
	void		*mlx;
	void		*win;
}	t_game;

#endif //CUB3D_H