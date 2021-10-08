/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:48:45 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 12:57:48 by kkamata          ###   ########.fr       */
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

t_bool		is_valid_args(t_game *game, int argc, char *argv[]);

// +------------------------------------------+ //
//   read/read.c                                //
// +------------------------------------------+ //

t_bool		read_berfile(t_game *game);

// +------------------------------------------+ //
//   read/matrix.c                              //
// +------------------------------------------+ //

t_bool		load_map_matrix(t_game *game);
t_bool		end_read_berfile(char *line, int fd, t_bool status);

// +------------------------------------------+ //
//   map/map.c                                  //
// +------------------------------------------+ //

void		init_map(t_game *game);
t_bool		new_map(t_game *game, char *line);
t_bool		parse_map(t_game *game);

// +------------------------------------------+ //
//   map/valid.c                                //
// +------------------------------------------+ //

t_bool		is_valid_elements(t_game *game);
t_bool		is_surrounded_by_wall(t_game *game, int x, int y);

// +------------------------------------------+ //
//   player/player.c                            //
// +------------------------------------------+ //

void		init_player(t_game *game);
void		render_player(t_game *game);
void		update_player(t_game *game, size_t x, size_t y);

// +------------------------------------------+ //
//   game/game.c                                //
// +------------------------------------------+ //

void		init_game(t_game *game);
void		game_loop(t_game *game);
int			finish_game(t_game *game);

// +------------------------------------------+ //
//   game/window.c                              //
// +------------------------------------------+ //

void		init_window(t_game *game);
void		init_image(t_game *game);

// +------------------------------------------+ //
//   game/sprites.c                             //
// +------------------------------------------+ //

void		init_sprites(t_game *game);

// +------------------------------------------+ //
//   game/key.c                                 //
// +------------------------------------------+ //

int			key_press(t_keycode keycode, t_game *game);

// +------------------------------------------+ //
//   position/position.c                        //
// +------------------------------------------+ //

size_t		locate_position(t_game *game, size_t position[2]);
size_t		locate_player_position(t_game *game);
t_bool		is_player_at(t_game *game, t_map_element element);

// +------------------------------------------+ //
//   render/render.c                            //
// +------------------------------------------+ //

void		render_map(t_game *game);
void		render_sprite(t_game *game, size_t position[2], t_element element);

// +------------------------------------------+ //
//   render/load.c                              //
// +------------------------------------------+ //

t_element	load_element(t_game *game, size_t index[2]);
uint32_t	load_color(t_game *game, size_t index[2], t_element element);

// +------------------------------------------+ //
//   utils/file.c                               //
// +------------------------------------------+ //

t_bool		is_valid_file(char *path_to_file);
t_bool		is_valid_extension(char *path_to_file, char *extension);

// +------------------------------------------+ //
//   utils/free.c                               //
// +------------------------------------------+ //

t_exit		free_map(t_game *game, t_exit status);
void		free_sprites(char **sprites, int time);

// +------------------------------------------+ //
//   error/error.c                              //
// +------------------------------------------+ //

t_bool		error_msg(char *msg);
t_bool		error_system(void);
t_bool		exit_game(t_game *game, char *msg, t_exit status);

#endif
