/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:51:31 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:16:31 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_pixel(t_game *game, int x, int y, uint32_t color)
{
	game->img.data[y * game->map.size[WIDTH] + x] = color;
}

t_element	load_element(t_game *game, int mapcoord[2])
{
	t_element	element;
	t_symbol	symbol;

	symbol = game->map.map[locate_position(game, mapcoord)];
	element = -1;
	while (SYMBOLS[++element])
	{
		if (SYMBOLS[element] == (char)symbol)
			return (element);
	}
	return (-1);
}
