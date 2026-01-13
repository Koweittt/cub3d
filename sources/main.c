/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narcisse <narcisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:57:37 by abignals          #+#    #+#             */
/*   Updated: 2026/01/11 02:38:10 by narcisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	init_game(&game);
	if (ac != 2)
	{
		write(2, "Error\nUsage: ./Cub3d <map.cub>\n", 31);
		return (1);
	}
	if (parse_file(av[1], &game) == -1)
		return (free_game(&game), 1);
	if (init_mlx(&game) == -1)
		return (free_game(&game), 1);
	if (load_textures(&game) == -1)
		return (free_game(&game), 1);
	init_player(&game);
	render_frame(&game);
	mlx_loop(game.mlx);
	return (0);
}
