/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:13:10 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:48:36 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
}
