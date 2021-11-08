# so_long

![game.png](https://github.com/knkamata/so_long/game.png)

## Goal
Build a small 2D game using [MinilibX](https://github.com/42Paris/minilibx-linux), a simple X-Window programming API in C.

## Requirements
MinilibX requires you to have the following Linux and macOS environments. Please see more details about [MinilibX](https://github.com/42Paris/minilibx-linux) from the link if you need.
### Requirements for Linux
- gcc
- make
- X11 include files (package xorg)
- XShm extension must be present (package libxext-dev)
- Utility functions from BSD systems - development files (package libbsd-dev)
```shell
# e.g. (Debian/Ubuntu)
$ sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
### Requirements for macOS
- [Xquartz](https://www.xquartz.org/)
```shell
# e.g.
$ brew install --cask xquartz
```

## Getting Started
```shell
$ git clone https://github.com/knkamata/so_long.git
$ cd so_long
```
```shell
# Game for the easy mode
$ make
$ ./so_long map/valid/normal
```
```shell
# Game with an enemy and a step counter
$ make bonus
$ ./so_long map/bonus/medium
```

## How to play
The player collects all the items on the map and escapes through the dug hole. 

| KEYBOARD | ACTION |
| -------- | ------ |
| `W`      | Move up |
| `S`      | Move down |
| `A`      | Move left |
| `D`      | Move right |
| `ESC`    | Close the game window |

## References
- [42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)
- [devleomk1/so_long](https://github.com/devleomk1/so_long)
