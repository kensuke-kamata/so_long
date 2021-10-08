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

SRCS		= $(SRCDIR)main.c \
			  $(SRCDIR)args/args.c \
			  $(SRCDIR)error/error.c \
			  $(SRCDIR)game/game.c \
			  $(SRCDIR)game/window.c \
			  $(SRCDIR)game/sprites.c \
			  $(SRCDIR)game/key.c \
			  $(SRCDIR)map/map.c \
			  $(SRCDIR)map/valid.c \
			  $(SRCDIR)player/player.c \
			  $(SRCDIR)position/position.c \
			  $(SRCDIR)read/read.c \
			  $(SRCDIR)read/matrix.c \
			  $(SRCDIR)render/render.c \
			  $(SRCDIR)render/graphics.c \
			  $(SRCDIR)utils/file.c \
			  $(SRCDIR)utils/free.c

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
