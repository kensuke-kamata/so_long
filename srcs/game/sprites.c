/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:48:51 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/14 22:25:24 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	end_init_sprite(char **sprites,
						int time,
						char *msg,
						t_bool status)
{
	int	i;

	i = 0;
	while (i < time)
		free(sprites[i++]);
	free(sprites);
	if (msg && *msg)
		error_msg(msg);
	return (status);
}

static char	**_init_sprite_field(void)
{
	char	**sprites;

	sprites = (char **)malloc(sizeof(char *) * ASSET_FIELD_TOTAL + 1);
	if (!sprites)
		return (NULL);
	sprites[EMPT] = ft_strdup(ASSET_FIELD0);
	sprites[WALL] = ft_strdup(ASSET_FIELD1);
	sprites[CLCT] = ft_strdup(ASSET_COLLECT);
	sprites[EXIT] = ft_strdup(ASSET_LADDER);
	sprites[STNE] = ft_strdup(ASSET_STONE);
	sprites[STEP] = ft_strdup(ASSET_SIGN);
	if (!sprites[EMPT] || !sprites[WALL] || !sprites[CLCT]
		|| !sprites[EXIT] || !sprites[STNE] || !sprites[STEP])
		end_init_sprite(sprites, ASSET_FIELD_TOTAL, "_init_sprite_field\n", FALSE);
	return (sprites);
}

static t_bool	init_sprite_field(t_game *game)
{
	int		i;
	char	**sprites;

	sprites = _init_sprite_field();
	if (!sprites)
		return (error_msg("init_sprit_field\n"));
	i = -1;
	while (++i < ASSET_FIELD_TOTAL)
	{
		game->field[i].img = mlx_xpm_file_to_image(
				game->mlx, sprites[i],
				&(game->field[i].size[WIDTH]),
				&(game->field[i].size[HEIGHT]));
		game->field[i].data = (int *)mlx_get_data_addr(
				game->field[i].img,
				&(game->field[i].bpp),
				&(game->field[i].size_line),
				&(game->field[i].endian));
		if (!game->field[i].img || !game->field[i].data)
			return (end_init_sprite(
				sprites, ASSET_FIELD_TOTAL,
				"init_sprite_field\n", FALSE));
	}
	return (end_init_sprite(sprites, ASSET_FIELD_TOTAL, NULL, TRUE));
}

static t_bool	_valid_sprite_player_null(char **sprites)
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

static t_bool	_mlx_player_xpm_to_image(t_game *game, int index[2], char **sprites)
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

static char	**_init_sprite_player(void)
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
		end_init_sprite(sprites, ASSET_PLAYER_TOTAL, "_init_sprite_player\n", FALSE);
	return (sprites);
}

static t_bool	init_sprite_player(t_game *game)
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
				return (end_init_sprite(sprites, ASSET_PLAYER_TOTAL, "init_sprite_player\n", FALSE));
		}
	}
	return (end_init_sprite(sprites, ASSET_PLAYER_TOTAL, NULL, TRUE));
}

static char	**_init_sprite_enemy(void)
{
	char	**sprites;

	sprites = (char **)malloc(sizeof(char *) * ASSET_ENEMY_TOTAL + 1);
	if (!sprites)
		return (NULL);
	sprites[NORTH] = ft_strdup(ASSET_ENEMY_N00);
	sprites[EAST] = ft_strdup(ASSET_ENEMY_E00);
	sprites[SOUTH] = ft_strdup(ASSET_ENEMY_S00);
	sprites[WEST] = ft_strdup(ASSET_ENEMY_W00);
	sprites[NONE] = ft_strdup(ASSET_EXCLAMATION);
	if (!sprites[NORTH] || !sprites[EAST] || !sprites[SOUTH]
		|| !sprites[WEST] || !sprites[NONE])
		end_init_sprite(sprites, ASSET_ENEMY_TOTAL, "_init_sprite_enemy\n", FALSE);
	return (sprites);
}

static t_bool	init_sprite_enemy(t_game *game)
{
	int		i;
	char	**sprites;

	sprites = _init_sprite_enemy();
	if (!sprites)
		return (error_msg("init_sprite_enemy\n"));
	i = -1;
	while (++i < ASSET_ENEMY_TOTAL)
	{
		game->enemy.e[i].img = mlx_xpm_file_to_image(
				game->mlx, sprites[i],
				&(game->enemy.e[i].size[WIDTH]),
				&(game->enemy.e[i].size[HEIGHT]));
		game->enemy.e[i].data = (int *)mlx_get_data_addr(
				game->enemy.e[i].img,
				&(game->enemy.e[i].bpp),
				&(game->enemy.e[i].size_line),
				&(game->enemy.e[i].endian));
		if (!game->enemy.e[i].img || !game->enemy.e[i].data)
			return (end_init_sprite(
				sprites, ASSET_ENEMY_TOTAL,
				"init_sprite_enemy\n", FALSE));
	}
	return (end_init_sprite(sprites, ASSET_ENEMY_TOTAL, NULL, TRUE));
}

t_bool	init_sprite(t_game *game)
{
	if (!init_sprite_field(game))
		return (FALSE);
	if (!init_sprite_player(game))
		return (FALSE);
	if (!init_sprite_enemy(game))
		return (FALSE);
	return (TRUE);
}