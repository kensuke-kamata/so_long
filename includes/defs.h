/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:33:21 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/19 15:25:19 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

// +------------------------------------------+ //
//   Const definition                           //
// +------------------------------------------+ //

// +--- Fundamentals --- + //
# define GAME_NAME "so_long"
# define TILE_SIZE 64
// +--- File extensions --- + //
# define BER_EXTENSION ".ber"
# define XPM_EXTENSION ".xpm"
// +--- Map symbols --- + //
# define SYMBOLS "01CESTPR"
// +--- Field --- + //
# define ASSET_FIELD_TOTAL 6
# define ASSET_FIELD0 "./assets/tile00.xpm"
# define ASSET_FIELD1 "./assets/tile01.xpm"
# define ASSET_LADDER "./assets/ladder.xpm"
# define ASSET_COLLECT "./assets/ball.xpm"
# define ASSET_STONE "./assets/stone.xpm"
# define ASSET_SIGN "./assets/sign.xpm"
// +--- Player --- + //
# define DIRECTIONS 4
# define FRAMES 3
# define ASSET_PLAYER_TOTAL 12
// +--- Player North --- + //
# define ASSET_PLAYER_N00 "./assets/player_n00.xpm"
# define ASSET_PLAYER_N01 "./assets/player_n01.xpm"
# define ASSET_PLAYER_N02 "./assets/player_n02.xpm"
// +--- Player East --- + //
# define ASSET_PLAYER_E00 "./assets/player_e00.xpm"
# define ASSET_PLAYER_E01 "./assets/player_e01.xpm"
# define ASSET_PLAYER_E02 "./assets/player_e02.xpm"
// +--- Player South --- + //
# define ASSET_PLAYER_S00 "./assets/player_s00.xpm"
# define ASSET_PLAYER_S01 "./assets/player_s01.xpm"
# define ASSET_PLAYER_S02 "./assets/player_s02.xpm"
// +--- Player South --- + //
# define ASSET_PLAYER_W00 "./assets/player_w00.xpm"
# define ASSET_PLAYER_W01 "./assets/player_w01.xpm"
# define ASSET_PLAYER_W02 "./assets/player_w02.xpm"
// +--- Enemy --- + //
# define ASSET_ENEMY_TOTAL 5
# define ASSET_ENEMY_N00 "./assets/rocket_n00.xpm"
# define ASSET_ENEMY_E00 "./assets/rocket_e00.xpm"
# define ASSET_ENEMY_S00 "./assets/rocket_s00.xpm"
# define ASSET_ENEMY_W00 "./assets/rocket_w00.xpm"
# define ASSET_EXCLAMATION "./assets/exclamation.xpm"
// +--- Move speed --- + //
# define PLAYER_SPEED 4
# define ENEMY_SPEED 8

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

typedef enum e_coord
{
	X,
	Y,
}	t_coord;

typedef enum e_direct
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	NONE,
}	t_direct;

typedef enum e_element
{
	EMPT,
	WALL,
	CLCT,
	EXIT,
	STNE,
	STEP,
	PLYR,
	ENEM,
}	t_element;

typedef enum e_symbol
{
	MAPSYM0	= '0',
	MAPSYM1	= '1',
	MAPSYMC	= 'C',
	MAPSYME	= 'E',
	MAPSYMS	= 'S',
	MAPSYMT	= 'T',
	MAPSYMP	= 'P',
	MAPSYMR	= 'R',
}	t_symbol;

typedef enum e_keycode
{
	KEY_A		= 0x61,
	KEY_S		= 0x73,
	KEY_D		= 0x64,
	KEY_W		= 0x77,
	KEY_RIGHT	= 0xff53,
	KEY_LEFT	= 0xff51,
	KEY_ESC		= 0xff1b,
}	t_keycode;

typedef enum e_event
{
	X_KEY_PRESS		= 2,
	X_KEY_RELEASE	= 3,
	X_EXPOSE		= 12,
	X_KEY_EXIT		= 33,
}	t_event;

typedef enum e_mask
{
	X_NO_EVENT_MASK			= 0L,
	X_KEY_PRESS_MASK		= 1L << 0,
	X_KEY_RELEASE_MASK		= 1L << 1,
	X_EXPOSURE_MASK			= 1L << 15,
	X_STRUCTURE_NOTIFY_MASK	= 1L << 17,
}	t_mask;

typedef enum e_color
{
	BLACK	= 0x00000000,
	RED		= 0x00ff0000,
	GRAY	= 0x00b3b3b3,
	WHITE	= 0x00ffffff,
	ALPHA	= 0xff000000,
}	t_color;

// +------------------------------------------+ //
//   Type definition                            //
// +------------------------------------------+ //

typedef struct s_flag
{
	t_bool		KEYDOWN;
	t_bool		PLAYER_RFOOT;
	t_bool		PLAYER_LFOOT;
	t_bool		PLAYER_FOUND;
	t_bool		PLAYER_GOAL;
	t_bool		ENEMY_WATCHING;
}	t_flag;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		size[2];
}	t_img;

typedef struct s_map
{
	char	*map;
	char	*submap;
	char	*path_to_file;
	int		matrix[2];
	int		size[2];
	int		exitcoord[2];
	int		collect;
}	t_map;

typedef struct s_player
{
	t_img	p[DIRECTIONS][FRAMES];
	int		stride[DIRECTIONS + 1][2];
	int		position[2];
	int		position0[2];
	int		direct;
	int		frame;
	int		steps;
	int		inc;
	t_bool	movable;
	t_bool	walking;
}	t_player;

typedef struct s_enemy
{
	t_img	e[DIRECTIONS + 1];
	t_bool	is_enemy;
	int		position[2];
	int		position0[2];
	int		direct;
	int		inc;
}	t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			fin;
	t_img		img;
	t_img		field[ASSET_FIELD_TOTAL];
	t_map		map;
	t_flag		flags;
	t_player	player;
	t_enemy		enemy;
}	t_game;

#endif
