/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:53:07 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 12:40:50 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (!is_valid_args(&game, argc, argv))
		return (FAILURE);
	if (!read_berfile(&game))
		return (FAILURE);
	if (!parse_map(&game))
		return (free_map(&game, FAILURE));
	init_game(&game);
	game_loop(&game);
	return (free_map(&game, SUCCESS));
}
