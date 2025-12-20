/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:56:50 by abignals          #+#    #+#             */
/*   Updated: 2025/12/17 20:03:57 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Wrong utilisation, use ./Cub3d <path_to_the_map>\n");
		return (1);
	}
}
