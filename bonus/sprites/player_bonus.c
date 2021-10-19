/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:52:25 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:17:02 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static
t_bool	_valid_sprite_player_null(char **sprites)
{
	int		index[2];

	index[Y] = -1;
	while (++index[Y] < DIRECTIONS)
	{
		index[X] = -1;
		while (++index[X] < FRAMES)
		{
			if (!sprites[index[Y] * FRAMES + index[X]])
				return (FALSE);
		}
	}
	return (TRUE);
}

static
t_bool	_mlx_player_xpm_to_image(t_game *game, int index[2], char **sprites)
{
	game->player.p[index[Y]][index[X]].img = mlx_xpm_file_to_image(
			game->mlx,
			sprites[index[Y] * FRAMES + index[X]],
			&(game->player.p[index[Y]][index[X]].size[WIDTH]),
			&(game->player.p[index[Y]][index[X]].size[HEIGHT]));
	game->player.p[index[Y]][index[X]].data = (int *)mlx_get_data_addr(
			game->player.p[index[Y]][index[X]].img,
			&(game->player.p[index[Y]][index[X]].bpp),
			&(game->player.p[index[Y]][index[X]].size_line),
			&(game->player.p[index[Y]][index[X]].endian));
	if (!game->player.p[index[Y]][index[X]].img
		|| !game->player.p[index[Y]][index[X]].data)
		return (FALSE);
	return (TRUE);
}

static
char	**_init_sprite_player(void)
{
	char	**sprites;

	sprites = (char **)malloc(sizeof(char *) * ASSET_PLAYER_TOTAL + 1);
	if (!sprites)
		return (NULL);
	sprites[NORTH * FRAMES + 0] = ft_strdup(ASSET_PLAYER_N00);
	sprites[NORTH * FRAMES + 1] = ft_strdup(ASSET_PLAYER_N01);
	sprites[NORTH * FRAMES + 2] = ft_strdup(ASSET_PLAYER_N02);
	sprites[EAST * FRAMES + 0] = ft_strdup(ASSET_PLAYER_E00);
	sprites[EAST * FRAMES + 1] = ft_strdup(ASSET_PLAYER_E01);
	sprites[EAST * FRAMES + 2] = ft_strdup(ASSET_PLAYER_E02);
	sprites[SOUTH * FRAMES + 0] = ft_strdup(ASSET_PLAYER_S00);
	sprites[SOUTH * FRAMES + 1] = ft_strdup(ASSET_PLAYER_S01);
	sprites[SOUTH * FRAMES + 2] = ft_strdup(ASSET_PLAYER_S02);
	sprites[WEST * FRAMES + 0] = ft_strdup(ASSET_PLAYER_W00);
	sprites[WEST * FRAMES + 1] = ft_strdup(ASSET_PLAYER_W01);
	sprites[WEST * FRAMES + 2] = ft_strdup(ASSET_PLAYER_W02);
	if (!_valid_sprite_player_null(sprites))
		end_init_sprite(
			sprites, ASSET_PLAYER_TOTAL,
			"_init_sprite_player\n", FALSE);
	return (sprites);
}

t_bool	init_sprite_player(t_game *game)
{
	int		index[2];
	char	**sprites;

	sprites = _init_sprite_player();
	if (!sprites)
		return (FALSE);
	index[Y] = -1;
	while (++index[Y] < DIRECTIONS)
	{
		index[X] = -1;
		while (++index[X] < FRAMES)
		{
			if (!_mlx_player_xpm_to_image(game, index, sprites))
				return (end_init_sprite(
						sprites, ASSET_PLAYER_TOTAL,
						"init_sprite_player\n", FALSE));
		}
	}
	return (end_init_sprite(sprites, ASSET_PLAYER_TOTAL, NULL, TRUE));
}
