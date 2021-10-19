/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:37:28 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:11:15 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_enemy(t_game *game)
{
	int		i;

	i = -1;
	game->enemy.is_enemy = FALSE;
	while (++i < game->map.matrix[ROW] * game->map.matrix[COL])
	{
		if (game->map.map[i] == MAPSYMR)
		{
			game->enemy.is_enemy = TRUE;
			game->enemy.position[X] = i % game->map.matrix[COL];
			game->enemy.position[Y] = i / game->map.matrix[COL];
			game->enemy.position0[X] = game->enemy.position[X];
			game->enemy.position0[Y] = game->enemy.position[Y];
			game->map.map[i] = MAPSYM0;
		}
	}
	game->enemy.direct = SOUTH;
}
