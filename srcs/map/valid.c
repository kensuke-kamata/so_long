/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:31:56 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/06 22:30:38 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	is_surrounded_by_wall(t_game *game, int x, int y)
{
	if (x < 0 || y < 0)
		return (FALSE);
	if (game->map.matrix[COL] <= (size_t)x || \
		game->map.matrix[ROW] <= (size_t)y)
		return (FALSE);
	if (game->map.submap[x + game->map.matrix[COL] * y] == CHAR_WALL)
		return (TRUE);
	game->map.submap[x + game->map.matrix[COL] * y] = CHAR_WALL;
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
	size_t	i;
	size_t	exit_count;
	size_t	player_count;

	i = 0;
	exit_count = 0;
	player_count = 0;
	while (i < game->map.matrix[ROW] * game->map.matrix[COL])
	{
		if (game->map.map[i] == CHAR_PLYR)
			player_count++;
		if (game->map.map[i] == CHAR_EXIT)
			exit_count++;
		if (game->map.map[i] == CHAR_CLCT)
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
