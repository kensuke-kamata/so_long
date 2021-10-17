/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:36:42 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/17 19:44:58 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static
t_bool	load_map_matrix(t_game *game, int fd)
{
	char	*line;

	while (get_next_line_beta(fd, &line) >= 0)
	{
		if (!line)
			return (TRUE);
		game->map.matrix[ROW]++;
		if (game->map.matrix[COL] != (int)ft_strlen(line))
			return (end_read(line, fd, FALSE));
		free(line);
	}
	return (end_read(line, fd, FALSE));
}

static
t_bool	load_map_col(t_game *game, int fd)
{
	char	*line;

	if (get_next_line_beta(fd, &line) < 1)
		return (end_read(line, fd, FALSE));
	game->map.matrix[COL] = (int)ft_strlen(line);
	game->map.matrix[ROW]++;
	free(line);
	return (TRUE);
}

static
void	load_map_size(t_game *game)
{
	game->map.size[WIDTH] = game->map.matrix[COL] * TILE_SIZE;
	game->map.size[HEIGHT] = game->map.matrix[ROW] * TILE_SIZE;
}

t_bool	load_map(t_game *game)
{
	int		fd;

	fd = open(game->map.path_to_file, O_RDONLY);
	if (!load_map_col(game, fd))
		return (FALSE);
	if (!load_map_matrix(game, fd))
		return (FALSE);
	load_map_size(game);
	return (end_read(NULL, fd, TRUE));
}
