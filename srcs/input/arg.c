/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:14:35 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/17 19:04:49 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	valid_arg(t_game *game, int argc, char *argv[])
{
	if (argc != 2)
		return (error_msg(ERRMSG_ARGS));
	if (!is_readable(argv[1]))
		return (error_msg(ERRMSG_INVFILE));
	if (!has_extension(argv[1], BER_EXTENSION))
		return (error_msg(ERRMSG_INVEXT));
	game->map.path_to_file = argv[1];
	return (TRUE);
}
