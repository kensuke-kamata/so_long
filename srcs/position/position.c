/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:50:39 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 09:57:58 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

size_t	locate_position(t_game *game, size_t position[2])
{
	return (position[X] + game->map.matrix[COL] * position[Y]);
}

size_t	locate_player_position(t_game *game)
{
	return (locate_position(game, game->player.position));
}

t_bool	is_player_located_at(t_game *game, t_elemchar element)
{
	return (game->map.map[locate_player_position(game)] == (char)element);
}
