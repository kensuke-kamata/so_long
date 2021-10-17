/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:26:02 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/17 21:40:24 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

uint32_t	load_exclamation_color(t_game *game, int imgcoord[2])
{
	float		ratio;
	int			index[2];
	uint32_t	color;

	ratio = (float)game->enemy.e[NONE].size[WIDTH] / TILE_SIZE;
	index[X] = imgcoord[X] * ratio;
	index[Y] = imgcoord[Y] * game->enemy.e[NONE].size[WIDTH] * ratio;
	color = game->enemy.e[NONE].data[index[X] + index[Y]];
	return (color);
}

void	render_exclamation(t_game *game)
{
	int			index[2];
	uint32_t	color;

	index[Y] = -1;
	while (++index[Y] < TILE_SIZE)
	{
		index[X] = -1;
		while (++index[X] < TILE_SIZE)
		{
			color = load_exclamation_color(game, index);
			if (color != ALPHA)
				render_pixel(
					game,
					index[X] + game->enemy.position[X] * TILE_SIZE,
					index[Y] + (game->enemy.position[Y] - 1) * TILE_SIZE,
					color);
		}
	}
}

uint32_t	load_enemy_color(t_game *game, int imgcoord[2])
{
	float		ratio;
	int			index[2];
	t_direct	direct;
	uint32_t	color;

	direct = game->enemy.direct;
	ratio = (float)game->enemy.e[direct].size[WIDTH] / TILE_SIZE;
	index[X] = imgcoord[X] * ratio;
	index[Y] = imgcoord[Y] * game->enemy.e[direct].size[WIDTH] * ratio;
	color = game->enemy.e[direct].data[index[X] + index[Y]];
	return (color);
}

static
void	render_enemy_sprite(t_game *game, int wincoord[2])
{
	int			index[2];
	uint32_t	color;

	index[Y] = -1;
	while (++index[Y] < TILE_SIZE * 2)
	{
		index[X] = -1;
		while (++index[X] < TILE_SIZE)
		{
			color = load_enemy_color(game, index);
			if (color != ALPHA)
				render_pixel(
					game,
					wincoord[X] + index[X],
					wincoord[Y] + index[Y],
					color);
		}
	}
}

void	render_enemy(t_game *game)
{
	int		wincoord[2];

	wincoord[X] = game->enemy.position[X] * TILE_SIZE;
	wincoord[Y] = (game->enemy.position[Y] - 1) * TILE_SIZE;
	game->enemy.inc += ENEMY_SPEED;
	game->flags.ENEMY_WATCHING = TRUE;
	if (game->enemy.inc >= 800)
	{
		game->enemy.inc = 0;
		game->flags.ENEMY_WATCHING = FALSE;
	}
	if (!game->flags.ENEMY_WATCHING && !game->flags.PLAYER_FOUND)
	{
		if (game->enemy.direct == 3)
			game->enemy.direct = 0;
		else
			game->enemy.direct++;
	}
	render_enemy_sprite(game, wincoord);
}
