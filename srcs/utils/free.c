/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:00:45 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/07 14:55:32 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_exit	free_map(t_game *game, t_exit status)
{
	free(game->map.map);
	return (status);
}

void	free_sprites(char **sprites, int time)
{
	int	i;

	i = 0;
	while (i < time)
		free(sprites[i++]);
	free(sprites);
}
