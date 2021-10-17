/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:04:11 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/17 19:04:39 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	has_extension(char *path_to_file, char *extension)
{
	char	*file_extension;

	file_extension = ft_strrchr(path_to_file, '.');
	if (!file_extension)
		return (FALSE);
	if (!ft_strcmp(file_extension, extension))
		return (TRUE);
	return (FALSE);
}

t_bool	is_readable(char *path_to_file)
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
