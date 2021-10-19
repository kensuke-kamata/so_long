/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:57:26 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 14:58:53 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
		end_init_sprite(
			sprites, ASSET_ENEMY_TOTAL,
			"_init_sprite_enemy\n", FALSE);
	return (sprites);
}

t_bool	init_sprite_enemy(t_game *game)
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
