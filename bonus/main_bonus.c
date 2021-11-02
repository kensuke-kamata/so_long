/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:53:07 by kkamata           #+#    #+#             */
/*   Updated: 2021/11/02 11:30:29 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// void end(void)__attribute__((destructor));
// void end(void) { system("leaks so_long"); }

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
