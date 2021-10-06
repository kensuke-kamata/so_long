/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:37:28 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/06 21:00:20 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_player(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map.matrix[ROW] * game->map.matrix[COL])
	{
		if (game->map.map[i] == CHAR_PLYR)
		{
			game->player.position[X] = i % game->map.matrix[COL];
			game->player.position[Y] = i / game->map.matrix[COL];
			game->map.map[i] = CHAR_EMPT;
		}
		i++;
	}
	game->player.move_count = 0;
}
