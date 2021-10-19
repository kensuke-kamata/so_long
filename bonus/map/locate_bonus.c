/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:50:39 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:15:31 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
