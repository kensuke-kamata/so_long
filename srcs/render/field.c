/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:37:32 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/17 21:37:24 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

uint32_t	load_field_color(t_game *game, int imgcoord[2], t_element element)
{
	float		ratio;
	int			index[2];
	uint32_t	color;

	ratio = (float)game->field[element].size[WIDTH] / TILE_SIZE;
	index[X] = imgcoord[X] * ratio;
	index[Y] = imgcoord[Y] * game->field[element].size[WIDTH] * ratio;
	color = game->field[element].data[index[X] + index[Y]];
	return (color);
}

void	render_field_sprite(t_game *game, int wincoord[2], t_element elem)
{
	int			index[2];
	uint32_t	color;

	index[Y] = -1;
	while (++index[Y] < TILE_SIZE)
	{
		index[X] = -1;
		while (++index[X] < TILE_SIZE)
		{
			color = load_field_color(game, index, elem);
			if (color != ALPHA)
				render_pixel(
					game,
					wincoord[X] + index[X],
					wincoord[Y] + index[Y],
					color);
		}
	}
}

void	render_field(t_game *game)
{
	int			mapcoord[2];
	int			wincoord[2];
	t_element	element;

	mapcoord[Y] = -1;
	while (++mapcoord[Y] < game->map.matrix[ROW])
	{
		mapcoord[X] = -1;
		while (++mapcoord[X] < game->map.matrix[COL])
		{
			wincoord[X] = mapcoord[X] * TILE_SIZE;
			wincoord[Y] = mapcoord[Y] * TILE_SIZE;
			render_field_sprite(game, wincoord, EMPT);
			element = load_element(game, mapcoord);
			render_field_sprite(game, wincoord, element);
		}
	}
}
