/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:48:45 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 15:00:39 by kkamata          ###   ########.fr       */
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
// +--- input --- + //
t_bool		valid_arg(t_game *game, int argc, char *argv[]);
t_bool		is_readable(char *path_to_file);
t_bool		has_extension(char *path_to_file, char *extension);
// +--- map --- + //
t_bool		read_map(t_game *game);
t_bool		load_map(t_game *game);
t_bool		parse_map(t_game *game);
t_bool		end_read(char *line, int fd, t_bool status);
// +--- map/locate --- + //
int			locate_position(t_game *game, int mapcoord[2]);
int			locate_player_position(t_game *game);
t_bool		is_player_at(t_game *game, t_symbol symbol);
// +--- game --- + //
t_bool		init_game(t_game *game);
t_bool		init_window(t_game *game);
t_bool		init_image(t_game *game);
t_bool		init_sprite(t_game *game);
void		init_player(t_game *game);
void		init_enemy(t_game *game);
void		game_loop(t_game *game);
int			finish_game(t_game *game);
// +--- game/key --- + //
int			key_press(t_keycode keycode, t_game *game);
void		update_player(t_game *game, int x, int y);
// +--- game/event --- + //
void		monitor_event(t_game *game);
// +--- sprites --- + //
t_bool		init_sprite_field(t_game *game);
t_bool		init_sprite_player(t_game *game);
t_bool		init_sprite_enemy(t_game *game);
t_bool		end_init_sprite(char **sprites, int time, char *msg, t_bool status);
// +--- render --- + //
void		render_pixel(t_game *game, int x, int y, uint32_t color);
void		render_field(t_game *game);
void		render_field_sprite(t_game *game, int wincoord[2], t_element elem);
void		render_player(t_game *game);
void		render_enemy(t_game *game);
void		render_counter(t_game *game);
void		render_exclamation(t_game *game);
// +--- render/load --- + //
t_element	load_element(t_game *game, int mapcoord[2]);
// +--- render/color --- + //
uint32_t	load_field_color(t_game *game, int imgcoord[2], t_element element);
uint32_t	load_player_color(t_game *game, int imgcoord[2]);
uint32_t	load_enemy_color(t_game *game, int imgcoord[2]);
uint32_t	load_exclamation_color(t_game *game, int imgcoord[2]);
// +--- utils --- + //
t_exit		free_map(t_game *game, t_exit status);
void		free_sprite_field(char **sprites, int time);
t_bool		error_msg(char *msg);
t_bool		error_system(void);
t_bool		exit_game(t_game *game, char *msg, t_exit status);

#endif
