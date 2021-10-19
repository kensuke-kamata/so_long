/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:53:07 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:18:54 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (!valid_arg(&game, argc, argv))
		return (FAILURE);
	if (!read_map(&game))
		return (FAILURE);
	if (!parse_map(&game))
		return (free_map(&game, FAILURE));
	if (!init_game(&game))
		return (free_map(&game, FAILURE));
	game_loop(&game);
	return (free_map(&game, SUCCESS));
}
