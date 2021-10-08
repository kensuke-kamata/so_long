/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:43:19 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 10:22:43 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_press(t_game *game, t_keycode keycode)
{
	if (keycode == KEY_W)
		printf("W\n");
	if (keycode == KEY_D)
		printf("D\n");
	if (keycode == KEY_S)
		printf("S\n");
	if (keycode == KEY_A)
		printf("A\n");
	if (keycode == KEY_ESC)
		printf("ESC\n");
	printf("Pressed\n");
	(void)game;
	return (0);
}
