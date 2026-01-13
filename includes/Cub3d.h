/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:58:21 by abignals          #+#    #+#             */
/*   Updated: 2026/01/12 19:49:36 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "Libft/libft.h"
# include "GNL/get_next_line_bonus.h"
# include "minilibx-linux/mlx.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_TITLE "Cub3D"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03
# define MOUSE_SENS 0.0001

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	t_rgb	*ceiling_color;
	t_rgb	*floor_color;
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

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	t_textures	textures;
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*win;
	t_img		screen;
	t_img		tex_north;
	t_img		tex_south;
	t_img		tex_east;
	t_img		tex_west;
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_left;
	int			key_right;
}	t_game;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_draw_params
{
	int		draw_start;
	int		draw_end;
	int		line_height;
	int		tex_x;
	t_img	*texture;
	double	step;
}	t_draw_params;

// Pars func
int		is_num(char c);
int		check_valid_chars(t_map *map);
int		extract_line_atoi(char *line, int i);
char	*extract_line(char *line, int i);
int		is_map_closed(t_map *map);
int		check_extension(char *filename);
int		check_extension_xpm(char *filename);
int		parse_textures(int fd, t_game *game);
void	init_game(t_game *game);
char	**copy_map(char **map, int height);
int		flood_fill(char **map, t_map *values);
void	free_map(char **map);
int		find_player(t_map *map);
int		parse_map(int fd, t_game *game);
int		validate_map(t_map *map);
int		is_empty_line(char *line);
char	**ft_realloc_map(char **map, int new_size);
int		parse_file(char *filename, t_game *game);

// Exec functions
int		init_mlx(t_game *game);
int		load_textures(t_game *game);
int		close_window(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
int		game_loop(t_game *game);
void	free_game(t_game *game);
void	render_frame(t_game *game);
int		rgb_to_int(t_rgb *rgb);
void	put_pixel(t_img *img, int x, int y, int color);
void	init_player(t_game *game);
void	cast_rays(t_game *game);
void	move_player(t_game *game);
void	rotate_player(t_game *game, double angle);
int		check_collision(t_game *game, double new_x, double new_y);
void	init_ray(t_game *game, t_ray *ray, int x);
void	set_step(t_game *game, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	draw_wall(t_game *game, t_ray *ray, int x);
int		get_texture_color(t_img *tex, int tex_x, int tex_y);
t_img	*get_wall_texture(t_game *game, t_ray *ray);
t_rgb	*fill_color(char *line, int i);
int		validate_textures(t_textures *tex);
int		verif_color(t_rgb *rgb);
t_rgb	*init_color(void);

#endif //CUB3D_H