/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:13:10 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/17 20:29:45 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static
t_bool	encounter_player(t_game *game, int enemy_x, int enemy_y)
{
	t_symbol	mapsymbol;

	mapsymbol = game->map.map[enemy_y * game->map.matrix[COL] + enemy_x];
	if (game->player.position[X] == enemy_x
		&& game->player.position[Y] == enemy_y)
		return (TRUE);
	if (mapsymbol == MAPSYM1 || mapsymbol == MAPSYMS)
		return (FALSE);
	if (game->enemy.direct == NORTH)
		return (encounter_player(game, enemy_x, --enemy_y));
	if (game->enemy.direct == EAST)
		return (encounter_player(game, ++enemy_x, enemy_y));
	if (game->enemy.direct == SOUTH)
		return (encounter_player(game, enemy_x, ++enemy_y));
	if (game->enemy.direct == WEST)
		return (encounter_player(game, --enemy_x, enemy_y));
	return (FALSE);
}

void	monitor_event(t_game *game)
{
	if (game->map.collect == 0)
		game->map.map[locate_position(game, game->map.exitcoord)] = MAPSYME;
	if (is_player_at(game, MAPSYME))
	{
		game->flags.PLAYER_GOAL = TRUE;
		game->fin += 1;
		if (game->fin >= 64 && !game->player.walking)
			game->player.direct = SOUTH;
		if (game->fin >= 128)
			finish_game(game);
	}
	if (encounter_player(
			game,
			game->enemy.position[X],
			game->enemy.position[Y]))
	{
		game->flags.PLAYER_FOUND = TRUE;
		render_exclamation(game);
		game->fin += 1;
		if (game->fin >= 128)
			finish_game(game);
	}
}
