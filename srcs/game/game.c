/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:56:03 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 15:26:28 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	finish_game(t_game *game)
{
	printf(MSG_FINISHGAME);
	mlx_clear_window(game->mlx, game->win);
	exit(free_map(game, SUCCESS));
}

static
t_bool	init_flags(t_game *game)
{
	game->flags.KEYDOWN = FALSE;
	game->flags.PLAYER_RFOOT = FALSE;
	game->flags.PLAYER_LFOOT = FALSE;
	game->flags.PLAYER_FOUND = FALSE;
	game->flags.PLAYER_GOAL = FALSE;
	game->flags.ENEMY_WATCHING = FALSE;
	game->fin = 0;
	return (TRUE);
}

static
int	main_loop(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	render_field(game);
	if (game->enemy.is_enemy)
		render_enemy(game);
	render_player(game);
	render_counter(game);
	monitor_event(game);
	return (0);
}

void	game_loop(t_game *game)
{
	mlx_hook(game->win, X_KEY_PRESS, X_KEY_PRESS_MASK, key_press, game);
	mlx_hook(game->win, X_KEY_EXIT, X_STRUCTURE_NOTIFY_MASK, finish_game, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

t_bool	init_game(t_game *game)
{
	if (!init_window(game))
		return (FALSE);
	if (!init_image(game))
		return (FALSE);
	if (!init_sprite(game))
		return (FALSE);
	if (!init_flags(game))
		return (FALSE);
	return (TRUE);
}
