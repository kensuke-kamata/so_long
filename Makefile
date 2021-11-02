# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 10:15:08 by kkamata           #+#    #+#              #
#    Updated: 2021/11/02 10:15:10 by kkamata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################################################
### Library name

NAME		= so_long

############################################################
### Variables used by implicit rules

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

############################################################
### Includes

INCLUDES	= -I./includes

############################################################
### Sources
##### Directories

SRCDIR		= ./srcs/
BNSDIR		= ./bonus/

##### Source files

SRC			= main.c \
			  input/arg.c \
			  input/valid.c \
			  map/map.c \
			  map/valid.c \
			  map/load.c \
			  map/locate.c \
			  game/game.c \
			  game/window.c \
			  game/player.c \
			  game/key.c \
			  game/event.c \
			  sprites/sprites.c \
			  sprites/field.c \
			  sprites/player.c \
			  render/render.c \
			  render/field.c \
			  render/player.c \
			  utils/free.c \
			  utils/error.c

SRC_B		= main_bonus.c \
			  input/arg_bonus.c \
			  input/valid_bonus.c \
			  map/map_bonus.c \
			  map/valid_bonus.c \
			  map/load_bonus.c \
			  map/locate_bonus.c \
			  game/game_bonus.c \
			  game/window_bonus.c \
			  game/player_bonus.c \
			  game/enemy_bonus.c \
			  game/key_bonus.c \
			  game/event_bonus.c \
			  sprites/sprites_bonus.c \
			  sprites/field_bonus.c \
			  sprites/player_bonus.c \
			  sprites/enemy_bonus.c \
			  render/render_bonus.c \
			  render/field_bonus.c \
			  render/player_bonus.c \
			  render/enemy_bonus.c \
			  render/counter_bonus.c \
			  utils/free_bonus.c \
			  utils/error_bonus.c

SRCS		= $(addprefix $(SRCDIR), $(SRC))
SRCS_B		= $(addprefix $(BNSDIR), $(SRC_B))

##### Object files

OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)
ifdef BONUS
OBJS		= $(OBJS_B)
endif

############################################################
### Library
##### libft

LIBFTPATH	= ./libft/
LIBFTMAKE	= $(MAKE) -C $(LIBFTPATH)
LIBFT		= -L$(LIBFTPATH) -lft

##### minilibx-linux

MLXPATH		= ./minilibx-linux/
MLXMAKE		= $(MAKE) -C $(MLXPATH)

ifeq ($(shell uname), Linux)
MLX			= -L$(MLXPATH) -lm -lmlx -lXext -lX11
else
MLX			= -L$(MLXPATH) -lmlx -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
endif

############################################################

.PHONY: all clean fclean re bonus

############################################################
### Rules

all: $(NAME)

$(MLXPATH):
	git clone https://github.com/42Paris/minilibx-linux.git

$(NAME): $(MLXPATH) $(OBJS)
	$(LIBFTMAKE)
	$(MLXMAKE)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(LIBFTMAKE) clean
	@if [ -d $(MLXPATH) ] ; then \
		$(MLXMAKE) clean ; \
	fi
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(LIBFTMAKE) fclean
	@if [ -d $(MLXPATH) ] ; then \
		$(MLXMAKE) clean ; \
		$(RM) $(MLXPATH)libmlx.a ; \
	fi
	$(RM) $(NAME)

re: fclean all

bonus:
	make BONUS=1

############################################################
