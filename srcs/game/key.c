/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:43:19 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/17 10:09:22 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	update_player_position(t_game *game, int x, int y)
{
	game->player.position[X] += x;
	game->player.position[Y] += y;
}

void	move2direct(t_game *game, t_direct direct)
{
	int		stride[2];

	game->player.position0[X] = game->player.position[X];
	game->player.position0[Y] = game->player.position[Y];
	game->player.direct = direct;
	stride[X] = game->player.stride[direct][X];
	stride[Y] = game->player.stride[direct][Y];
	if (game->flags.PLAYER_LFOOT)
	{
		game->flags.PLAYER_LFOOT = FALSE;
		game->flags.PLAYER_RFOOT = TRUE;
		game->player.frame = 1;
	}
	else if (game->flags.PLAYER_RFOOT)
	{
		game->flags.PLAYER_RFOOT = FALSE;
		game->flags.PLAYER_LFOOT = TRUE;
		game->player.frame = 2;
	}
	else
	{
		game->flags.PLAYER_RFOOT = TRUE;
		game->player.frame = 1;
	}
	update_player_position(game, stride[X], stride[Y]);
	if (is_player_at(game, MAPSYM1) || is_player_at(game, MAPSYMS)
		|| (game->player.position[X] == game->enemy.position[X]
		&& game->player.position[Y] == game->enemy.position[Y]))
	{
		update_player_position(game, -stride[X], -stride[Y]);
		game->player.movable = FALSE;
	}
	else
	{
		printf("%s: %d\n", MSG_MOVECOUNT, ++game->player.steps);
		game->player.movable = TRUE;
	}
	if (is_player_at(game, MAPSYMC))
	{
		game->map.map[locate_player_position(game)] = MAPSYM0;
		game->map.collect--;
	}
	game->player.walking = TRUE;
}

int	key_press(t_keycode keycode, t_game *game)
{
	if (!game->flags.KEYDOWN && !game->flags.PLAYER_GOAL && !game->flags.PLAYER_FOUND)
	{
		if (keycode == KEY_W)
			move2direct(game, NORTH);
		if (keycode == KEY_D)
			move2direct(game, EAST);
		if (keycode == KEY_S)
			move2direct(game, SOUTH);
		if (keycode == KEY_A)
			move2direct(game, WEST);
	}
	if (keycode == KEY_ESC)
		finish_game(game);
	return (0);
}
