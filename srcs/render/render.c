/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:04:31 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 12:58:55 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_pixel(t_game *game,
					 size_t index[2],
					 size_t position[2],
					 uint32_t color)
{
	game->img.data[(position[X] + index[X]) \
					+ game->map.size[WIDTH] \
					* (position[Y] + index[Y])] = color;
}

// Renders a sprite passed as an element at the position(x, y)
void	render_sprite(t_game *game, size_t position[2], t_element element)
{
	size_t		index[2];
	uint32_t	color;

	index[Y] = 0;
	while (index[Y] < TILE_SIZE)
	{
		index[X] = 0;
		while (index[X] < TILE_SIZE)
		{
			color = load_color(game, index, element);
			if (color != ALPHA && color != BLACK)
				render_pixel(game, index, position, color);
			index[X]++;
		}
		index[Y]++;
	}
}

void	render_map(t_game *game)
{
	size_t		index[2];
	size_t		position[2];
	t_element	element;

	index[Y] = 0;
	while (index[Y] < game->map.matrix[ROW])
	{
		index[X] = 0;
		while (index[X] < game->map.matrix[COL])
		{
			position[X] = index[X] * TILE_SIZE;
			position[Y] = index[Y] * TILE_SIZE;
			render_sprite(game, position, EMPT);
			element = load_element(game, index);
			render_sprite(game, position, element);
			index[X]++;
		}
		index[Y]++;
	}
}
