/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:43:19 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 11:45:25 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_press(t_keycode keycode, t_game *game)
{
	if (keycode == KEY_W)
		update_player(game, 0, -1);
	if (keycode == KEY_D)
		update_player(game, 1, 0);
	if (keycode == KEY_S)
		update_player(game, 0, 1);
	if (keycode == KEY_A)
		update_player(game, -1, 0);
	if (keycode == KEY_ESC)
		finish_game(game);
	return (0);
}
