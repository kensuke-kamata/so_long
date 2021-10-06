/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:33:21 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/06 21:15:27 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

// +------------------------------------------+ //
//   Const definition                           //
// +------------------------------------------+ //

# define GAME_NAME "so_long"
# define TILE_SIZE 64
# define BER_EXTENSION ".ber"
# define XPM_EXTENSION ".xpm"
# define MAP_ELEMENTS "01CEP"

// +------------------------------------------+ //
//   Enum definition                            //
// +------------------------------------------+ //

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum e_exit
{
	SUCCESS,
	FAILURE,
}	t_exit;

typedef enum e_matrix
{
	ROW,
	COL,
}	t_matrix;

typedef enum e_size
{
	WIDTH,
	HEIGHT,
}	t_size;

typedef enum e_position
{
	X,
	Y,
}	t_position;

typedef enum e_element
{
	CHAR_EMPT = '0',
	CHAR_WALL = '1',
	CHAR_CLCT = 'C',
	CHAR_EXIT = 'E',
	CHAR_PLYR = 'P',
}	t_element;

// +------------------------------------------+ //
//   Type definition                            //
// +------------------------------------------+ //

typedef struct s_player
{
	int	position[2];
	int	move_count;
}	t_player;

typedef struct s_map
{
	char	*map;
	char	*submap;
	char	*path_to_file;
	size_t	matrix[2];
	size_t	size[2];
	size_t	collectables;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
}	t_game;

#endif
