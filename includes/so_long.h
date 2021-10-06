/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:48:45 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/06 22:48:39 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// +------------------------------------------+ //
//   Libft                                      //
// +------------------------------------------+ //

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

// +------------------------------------------+ //
//   MinilibX                                   //
// +------------------------------------------+ //

# include "../minilibx-linux/mlx.h"

// +------------------------------------------+ //
//   Includes                                   //
// +------------------------------------------+ //

# include "defs.h"
# include "msgs.h"

// +------------------------------------------+ //
//   System header files                        //
// +------------------------------------------+ //

# include <fcntl.h>
# include <stdio.h>

// +------------------------------------------+ //
//   Prototypes                                 //
// +------------------------------------------+ //
// +------------------------------------------+ //
//   args/args.c                                //
// +------------------------------------------+ //

t_bool	is_valid_args(t_game *game, int argc, char *argv[]);

// +------------------------------------------+ //
//   read/read.c                                //
// +------------------------------------------+ //

t_bool	read_berfile(t_game *game);

// +------------------------------------------+ //
//   read/matrix.c                              //
// +------------------------------------------+ //

t_bool	get_map_matrix(t_game *game);
t_bool	end_read_berfile(char *line, int fd, t_bool status);

// +------------------------------------------+ //
//   map/map.c                                  //
// +------------------------------------------+ //

void	init_map(t_game *game);
t_bool	new_map(t_game *game, char *line);
t_bool	parse_map(t_game *game);

// +------------------------------------------+ //
//   map/valid.c                                //
// +------------------------------------------+ //

t_bool	is_valid_elements(t_game *game);
t_bool	is_surrounded_by_wall(t_game *game, int x, int y);

// +------------------------------------------+ //
//   player/player.c                            //
// +------------------------------------------+ //

void	init_player(t_game *game);

// +------------------------------------------+ //
//   utils/free.c                               //
// +------------------------------------------+ //

t_exit	free_map(t_game *game, t_exit status);

// +------------------------------------------+ //
//   error/error.c                              //
// +------------------------------------------+ //

t_bool	error_msg(char *msg);
t_bool	error_system(void);

#endif
