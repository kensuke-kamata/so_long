/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:04:31 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:25:17 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static
uint32_t	load_player_color(t_game *game, int imgcoord[2])
{
	float		ratio;
	int			index[2];
	int			frame;
	t_direct	direct;
	uint32_t	color;

	direct = game->player.direct;
	frame = game->player.frame;
	ratio = (float)game->player.p[direct][frame].size[WIDTH] / TILE_SIZE;
	index[X] = imgcoord[X] * ratio;
	index[Y] = imgcoord[Y] * game->player.p[direct][frame].size[WIDTH] * ratio;
	color = game->player.p[direct][frame].data[index[X] + index[Y]];
	return (color);
}

static
void	render_player_sprite(t_game *game, int wincoord[2])
{
	int			index[2];
	uint32_t	color;

	index[Y] = -1;
	while (++index[Y] < TILE_SIZE * 2)
	{
		index[X] = -1;
		while (++index[X] < TILE_SIZE)
		{
			color = load_player_color(game, index);
			if (color != ALPHA)
				render_pixel(
					game,
					wincoord[X] + index[X],
					wincoord[Y] + index[Y],
					color);
		}
	}
}

static
void	render_player_walking(t_game *game, int *wincoord)
{
	int			stride[2];
	int			*inc;
	t_bool		movable;

	stride[X] = game->player.stride[game->player.direct][X];
	stride[Y] = game->player.stride[game->player.direct][Y];
	inc = &(game->player.inc);
	movable = game->player.movable;
	wincoord[X] = game->player.position0[X] * TILE_SIZE
		+ stride[X] * (*inc) * movable;
	wincoord[Y] = (game->player.position0[Y] - 1) * TILE_SIZE
		+ stride[Y] * (*inc) * movable;
	*inc += PLAYER_SPEED;
	if (*inc >= 64)
	{
		*inc = 0;
		game->player.walking = FALSE;
		game->flags.KEYDOWN = FALSE;
	}
}

void	render_player(t_game *game)
{
	int		wincoord[2];

	if (game->player.walking)
	{
		game->flags.KEYDOWN = TRUE;
		render_player_walking(game, wincoord);
	}
	else
	{
		game->player.frame = 0;
		wincoord[X] = game->player.position[X] * TILE_SIZE;
		wincoord[Y] = (game->player.position[Y] - 1) * TILE_SIZE;
	}
	render_player_sprite(game, wincoord);
}
