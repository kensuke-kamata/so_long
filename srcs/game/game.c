/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:56:03 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 10:14:11 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int		finish_game(t_game *game)
{
	ft_printf(MSG_FINISHGAME);
	mlx_clear_window(game->mlx, game->win);
	exit(free_map(game, SUCCESS));
}

void	monitor_finish(t_game *game)
{
	if (is_player_located_at(game, CHAR_EXIT) && game->map.collectables == 0)
		finish_game(game);
}

int		main_loop(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	render_map(game);
	// render_player(game);
	monitor_finish(game);
	return (0);
}

void	game_loop(t_game *game)
{
	mlx_hook(game->win, X_KEY_PRESS, X_KEY_PRESS_MASK, key_press, game);
	mlx_hook(game->win, X_KEY_EXIT, X_STRUCTURE_NOTIFY_MASK, finish_game, game);
	// <- mlx_hook for expose (X_KEY = 12)?
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

void	init_game(t_game *game)
{
	init_window(game);
	init_image(game);
	init_sprites(game);
}
