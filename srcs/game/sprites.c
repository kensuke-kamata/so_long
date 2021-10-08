/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:24:24 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 09:55:20 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	is_valid_sprites(char **sprites)
{
	size_t	i;
	t_bool	is_valid;

	i = 0;
	is_valid = TRUE;
	while (i < SPRITE_NUM)
	{
		if (!is_valid_file(sprites[i]))
			is_valid = FALSE;
		if (!is_valid_extension(sprites[i], XPM_EXTENSION))
			is_valid = FALSE;
		i++;
	}
	return (is_valid);
}

char	**load_sprite_files(void)
{
	char	**sprites;

	sprites = (char **)malloc(sizeof(char *) * (SPRITE_NUM + 1));
	if (!sprites)
		return (NULL);
	sprites[EMPT] = ft_strdup(SPRITE_EMPT);
	sprites[WALL] = ft_strdup(SPRITE_WALL);
	sprites[CLCT] = ft_strdup(SPRITE_CLCT);
	sprites[EXIT] = ft_strdup(SPRITE_EXIT);
	sprites[PLYR] = ft_strdup(SPRITE_PLYR);
	return (sprites);
}

void	init_sprites(t_game *game)
{
	size_t	i;
	char	**sprites;

	sprites = load_sprite_files();
	if (!is_valid_sprites(sprites))
	{
		free_sprites(sprites, SPRITE_NUM);
		exit_game(game, ERRMSG_INVSPRITE, FAILURE);
	}
	i = 0;
	while (i < SPRITE_NUM)
	{
		game->sprites[i].sprite = mlx_xpm_file_to_image(
			game->mlx,
			sprites[i],
			&(game->sprites[i].size[WIDTH]),
			&(game->sprites[i].size[HEIGHT]));
		game->sprites[i].data = (int *)mlx_get_data_addr(
			game->sprites[i].sprite,
			&(game->sprites[i].bpp),
			&(game->sprites[i].size_line),
			&(game->sprites[i].endian));
		i++;
	}
	free_sprites(sprites, SPRITE_NUM);
}
