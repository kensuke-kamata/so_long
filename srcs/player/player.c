/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:37:28 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 17:26:06 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_player_position(t_game *game, int64_t x, int64_t y)
{
	game->player.position[X] += x;
	game->player.position[Y] += y;
}

void	update_player(t_game *game, int64_t x, int64_t y)
{
	update_player_position(game, x, y);
	if (is_player_at(game, MAP_WALL))
		update_player_position(game, -x, -y);
	else
		printf("%s: %llu\n", MSG_MOVECOUNT, ++game->player.move_count);
	if (is_player_at(game, MAP_CLCT))
	{
		game->map.map[locate_player_position(game)] = MAP_EMPT;
		game->map.collectables--;
	}
}

void	render_player(t_game *game)
{
	int64_t		position[2];

	position[X] = game->player.position[X] * TILE_SIZE;
	position[Y] = game->player.position[Y] * TILE_SIZE;
	render_sprite(game, position, PLYR);
}

void	init_player(t_game *game)
{
	int64_t		i;

	i = 0;
	while (i < game->map.matrix[ROW] * game->map.matrix[COL])
	{
		if (game->map.map[i] == MAP_PLYR)
		{
			game->player.position[X] = i % game->map.matrix[COL];
			game->player.position[Y] = i / game->map.matrix[COL];
			game->map.map[i] = MAP_EMPT;
		}
		i++;
	}
	game->player.move_count = 0;
}
