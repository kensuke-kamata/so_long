/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:26:26 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 16:26:12 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool	error_system(void)
{
	perror(ERRMSG);
	return (FALSE);
}

t_bool	error_msg(char *msg)
{
	printf("%s: %s", ERRMSG, msg);
	return (FALSE);
}

t_bool	exit_game(t_game *game, char *msg, t_exit status)
{
	error_msg(msg);
	exit(free_map(game, status));
}
