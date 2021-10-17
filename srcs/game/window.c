/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:04:26 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/16 19:37:52 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_image(t_game *game)
{
	game->img.img = mlx_new_image(
			game->mlx,
			game->map.size[WIDTH],
			game->map.size[HEIGHT]);
	if (!game->img.img)
		return (error_msg("mlx_new_image\n"));
	game->img.data = (int *)mlx_get_data_addr(
			game->img.img,
			&game->img.bpp,
			&game->img.size_line,
			&game->img.endian);
	if (!game->img.data)
		return (error_msg("mlx_get_data_addr\n"));
	return (TRUE);
}

t_bool	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_msg("mlx_init\n"));
	game->win = mlx_new_window(
			game->mlx,
			game->map.size[WIDTH],
			game->map.size[HEIGHT],
			GAME_NAME);
	if (!game->win)
		return (error_msg("mlx_new_window\n"));
	return (TRUE);
}
