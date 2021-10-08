/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:31:56 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/09 05:52:41 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	is_surrounded_by_wall(t_game *game, int64_t x, int64_t y)
{
	if (x < 0 || y < 0)
		return (FALSE);
	if (game->map.matrix[COL] <= x || \
		game->map.matrix[ROW] <= y)
		return (FALSE);
	if (game->map.submap[x + game->map.matrix[COL] * y] == MAP_WALL)
		return (TRUE);
	game->map.submap[x + game->map.matrix[COL] * y] = MAP_WALL;
	if (!is_surrounded_by_wall(game, x + 1, y))
		return (FALSE);
	if (!is_surrounded_by_wall(game, x - 1, y))
		return (FALSE);
	if (!is_surrounded_by_wall(game, x, y + 1))
		return (FALSE);
	if (!is_surrounded_by_wall(game, x, y - 1))
		return (FALSE);
	return (TRUE);
}

t_bool	is_valid_elements(t_game *game)
{
	int64_t		i;
	uint64_t	exit_count;
	uint64_t	player_count;

	i = 0;
	exit_count = 0;
	player_count = 0;
	while (i < game->map.matrix[ROW] * game->map.matrix[COL])
	{
		if (game->map.map[i] == MAP_PLYR)
			player_count++;
		if (game->map.map[i] == MAP_EXIT)
			exit_count++;
		if (game->map.map[i] == MAP_CLCT)
			game->map.collectables++;
		if (!ft_strchr(MAP_ELEMENTS, game->map.map[i++]))
			return (FALSE);
	}
	if (player_count != 1)
		return (FALSE);
	if (exit_count < 1)
		return (FALSE);
	if (game->map.collectables < 1)
		return (FALSE);
	return (TRUE);
}
