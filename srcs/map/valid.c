/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:31:56 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:41:25 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static
t_bool	is_surrounded_by_wall(t_game *game, int x, int y)
{
	if (x < 0 || y < 0)
		return (FALSE);
	if (game->map.matrix[COL] <= x || game->map.matrix[ROW] <= y)
		return (FALSE);
	if (game->map.submap[x + game->map.matrix[COL] * y] == MAPSYM1)
		return (TRUE);
	game->map.submap[x + game->map.matrix[COL] * y] = MAPSYM1;
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

static
void	init_exitcoord(t_game *game, int i, int *exit_count)
{
	game->map.exitcoord[X] = i % game->map.matrix[COL];
	game->map.exitcoord[Y] = i / game->map.matrix[COL];
	game->map.map[i] = MAPSYMS;
	*exit_count += 1;
}

static
t_bool	has_elements(t_game *game)
{
	int		i;
	int		exit_count;
	int		player_count;

	i = -1;
	exit_count = 0;
	player_count = 0;
	while (++i < game->map.matrix[ROW] * game->map.matrix[COL])
	{
		if (game->map.map[i] == MAPSYMP)
			player_count++;
		if (game->map.map[i] == MAPSYME)
			init_exitcoord(game, i, &exit_count);
		if (game->map.map[i] == MAPSYMC)
			game->map.collect++;
		if (!ft_strchr(SYMBOLS, game->map.map[i]))
			return (FALSE);
	}
	if (player_count != 1)
		return (FALSE);
	if (exit_count < 1)
		return (FALSE);
	if (game->map.collect < 1)
		return (FALSE);
	return (TRUE);
}

static
t_bool	dup_map(t_game *game)
{
	game->map.submap = ft_strdup(game->map.map);
	if (!game->map.submap)
		return (error_system());
	return (TRUE);
}

t_bool	parse_map(t_game *game)
{
	if (!has_elements(game))
		return (error_msg(ERRMSG_INVELEMENT));
	init_player(game);
	if (!dup_map(game))
		return (FALSE);
	if (!is_surrounded_by_wall(
			game,
			game->player.position[X],
			game->player.position[Y]))
	{
		free(game->map.submap);
		return (error_msg(ERRMSG_SURROUNDED));
	}
	free(game->map.submap);
	return (TRUE);
}
