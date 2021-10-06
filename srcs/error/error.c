/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:26:26 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/06 22:43:33 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	error_system(void)
{
	perror(ERRMSG);
	return (FALSE);
}

t_bool	error_msg(char *msg)
{
	ft_printf("%s: %s", ERRMSG, msg);
	return (FALSE);
}
