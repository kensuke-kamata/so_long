/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:48:51 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:43:59 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	end_init_sprite(char **sprites, int time,
						char *msg, t_bool status)
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

t_bool	init_sprite(t_game *game)
{
	if (!init_sprite_field(game))
		return (FALSE);
	if (!init_sprite_player(game))
		return (FALSE);
	return (TRUE);
}
