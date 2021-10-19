/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:49:08 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 17:01:46 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static
char	**_init_sprite_field(void)
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
	if (!sprites[EMPT] || !sprites[WALL] || !sprites[CLCT]
		|| !sprites[EXIT] || !sprites[STNE])
		end_init_sprite(
			sprites, ASSET_FIELD_TOTAL,
			"_init_sprite_field\n", FALSE);
	return (sprites);
}

t_bool	init_sprite_field(t_game *game)
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
