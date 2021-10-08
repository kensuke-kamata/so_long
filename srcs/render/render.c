/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:04:31 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 10:08:54 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

size_t	find_index(char *s, char c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (*s)
	{
		if (*s == c)
			return (i);
		s++;
		i++;
	}
	return (-1);
}

t_element	load_element(t_game *game, size_t index[2])
{
	t_elemchar	c;

	c = game->map.map[locate_position(game, index)];
	return (find_index(MAP_ELEMENTS, c));
}

uint32_t	load_color(t_game *game, size_t index[2], t_element element)
{
	float		ratio;
	size_t		position[2];
	uint32_t	color;

	ratio = (float)game->sprites[element].size[WIDTH] / TILE_SIZE;
	position[X] = index[X] * ratio;
	position[Y] = index[Y] * game->sprites[element].size[WIDTH] * ratio;
	color = game->sprites[element].data[position[X] + position[Y]];
	return (color);
}

void	render_pixel(t_game *game, size_t index[2], size_t position[2], uint32_t color)
{
	game->img.data[(position[X] + index[X]) \
					+ game->map.size[WIDTH] \
					* (position[Y] + index[Y])] = color;
}

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
