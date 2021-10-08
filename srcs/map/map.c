/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:07:01 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 16:53:34 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	dup_map(t_game *game)
{
	game->map.submap = ft_strdup(game->map.map);
	if (!game->map.submap)
		return (error_system());
	return (TRUE);
}

t_bool	parse_map(t_game *game)
{
	if (!is_valid_elements(game))
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

t_bool	new_map(t_game *game, char *line)
{
	char	*newmap;

	newmap = ft_strjoin(game->map.map, line);
	if (!newmap)
		return (error_system());
	free(game->map.map);
	game->map.map = newmap;
	return (TRUE);
}

void	init_map(t_game *game)
{
	game->map.map = NULL;
	game->map.submap = NULL;
	game->map.matrix[COL] = 0;
	game->map.matrix[ROW] = 0;
	game->map.size[WIDTH] = 0;
	game->map.size[HEIGHT] = 0;
	game->map.collectables = 0;
}
