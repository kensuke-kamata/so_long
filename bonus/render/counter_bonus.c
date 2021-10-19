/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:41:24 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:16:06 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_counter(t_game *game)
{
	int		index[2];
	char	*str;

	index[X] = 0;
	index[Y] = 0;
	game->map.map[0] = MAPSYMT;
	render_field_sprite(game, index, STEP);
	str = ft_itoa(game->player.steps);
	mlx_string_put(game->mlx, game->win, 28, 34, 0x000000, str);
	free(str);
}
