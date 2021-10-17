/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:50:39 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/17 22:12:01 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	locate_position(t_game *game, int mapcoord[2])
{
	return (game->map.matrix[COL] * mapcoord[Y] + mapcoord[X]);
}

int	locate_player_position(t_game *game)
{
	return (locate_position(game, game->player.position));
}

t_bool	is_player_at(t_game *game, t_symbol symbol)
{
	return (game->map.map[locate_player_position(game)] == (char)symbol);
}
