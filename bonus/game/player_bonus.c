/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:37:28 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:12:29 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static
void	_init_player_stride(t_game *game)
{
	game->player.stride[NORTH][X] = 0;
	game->player.stride[NORTH][Y] = -1;
	game->player.stride[EAST][X] = 1;
	game->player.stride[EAST][Y] = 0;
	game->player.stride[SOUTH][X] = 0;
	game->player.stride[SOUTH][Y] = 1;
	game->player.stride[WEST][X] = -1;
	game->player.stride[WEST][Y] = 0;
	game->player.stride[NONE][X] = 0;
	game->player.stride[NONE][Y] = 0;
}

static
void	_init_player(t_game *game)
{
	game->player.direct = SOUTH;
	game->player.frame = 0;
	game->player.steps = 0;
	game->player.inc = 0;
	game->player.movable = FALSE;
	game->player.walking = FALSE;
}

void	init_player(t_game *game)
{
	int		i;

	i = -1;
	while (++i < game->map.matrix[ROW] * game->map.matrix[COL])
	{
		if (game->map.map[i] == MAPSYMP)
		{
			game->player.position[X] = i % game->map.matrix[COL];
			game->player.position[Y] = i / game->map.matrix[COL];
			game->player.position0[X] = game->player.position[X];
			game->player.position0[Y] = game->player.position[Y];
			game->map.map[i] = MAPSYM0;
		}
	}
	_init_player(game);
	_init_player_stride(game);
}
