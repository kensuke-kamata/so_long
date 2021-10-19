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
			  game/enemy.c \
			  game/sprites.c \
			  game/key.c \
			  game/event.c \
			  sprites/field.c \
			  sprites/player.c \
			  sprites/enemy.c \
			  render/render.c \
			  render/field.c \
			  render/player.c \
			  render/enemy.c \
			  render/counter.c \
			  utils/free.c \
			  utils/error.c

SRCS		= $(addprefix $(SRCDIR), $(SRC))

##### Object files

OBJS		= $(SRCS:.c=.o)

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

.PHONY: all clean fclean re

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
	$(RM) $(OBJS)

fclean: clean
	$(LIBFTMAKE) fclean
	@if [ -d $(MLXPATH) ] ; then \
		$(MLXMAKE) clean ; \
		$(RM) $(MLXPATH)libmlx.a ; \
	fi
	$(RM) $(NAME)

re: fclean all

############################################################
