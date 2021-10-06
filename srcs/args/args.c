/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:14:35 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/06 22:42:09 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_bool	is_valid_extension(char *path_to_file, char *extension)
{
	char	*file_extension;

	file_extension = ft_strrchr(path_to_file, '.');
	if (!file_extension)
		return (FALSE);
	if (!ft_strcmp(file_extension, extension))
		return (TRUE);
	return (FALSE);
}

static t_bool	is_valid_file(char *path_to_file)
{
	int		fd;
	char	buf[2];

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	if (read(fd, buf, 1) == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

t_bool	is_valid_args(t_game *game, int argc, char *argv[])
{
	if (argc != 2)
		return (error_msg(ERRMSG_ARGS));
	if (!is_valid_file(argv[1]))
		return (error_msg(ERRMSG_INVFILE));
	if (!is_valid_extension(argv[1], BER_EXTENSION))
		return (error_msg(ERRMSG_INVEXT));
	game->map.path_to_file = argv[1];
	return (TRUE);
}
