/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:07:01 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/17 20:03:47 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	end_read(char *line, int fd, t_bool status)
{
	free(line);
	close(fd);
	return (status);
}

static
t_bool	new_map(t_game *game, char *line)
{
	char	*newmap;

	newmap = ft_strjoin(game->map.map, line);
	if (!newmap)
		return (error_system());
	free(game->map.map);
	game->map.map = newmap;
	return (TRUE);
}

static
void	init_map(t_game *game)
{
	game->map.map = NULL;
	game->map.submap = NULL;
	game->map.matrix[COL] = 0;
	game->map.matrix[ROW] = 0;
	game->map.size[WIDTH] = 0;
	game->map.size[HEIGHT] = 0;
	game->map.collect = 0;
}

t_bool	read_map(t_game *game)
{
	int		fd;
	char	*line;

	init_map(game);
	if (!load_map(game))
		return (error_msg(ERRMSG_INVMAP));
	fd = open(game->map.path_to_file, O_RDONLY);
	while (get_next_line_beta(fd, &line) >= 0)
	{
		if (!line)
			return (end_read(line, fd, TRUE));
		if (!new_map(game, line))
			return (end_read(line, fd, FALSE));
		free(line);
	}
	return (end_read(line, fd, FALSE));
}
