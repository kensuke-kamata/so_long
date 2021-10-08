/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:04:26 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 13:01:20 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_image(t_game *game)
{
	game->img.img = mlx_new_image(
			game->mlx,
			game->map.size[WIDTH],
			game->map.size[HEIGHT]);
	game->img.data = (int *)mlx_get_data_addr(
			game->img.img,
			&game->img.bpp,
			&game->img.size_line,
			&game->img.endian);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(
			game->mlx,
			game->map.size[WIDTH],
			game->map.size[HEIGHT],
			GAME_NAME);
}
