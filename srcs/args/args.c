/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:14:35 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/07 14:45:18 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
