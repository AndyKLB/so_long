# so_long

Summary
-------
`so_long` is a small 2D game project using the MiniLibX library. The player navigates a map to collect objects and reach an exit while avoiding invalid map configurations.

Features
--------
- Tile-based 2D map rendering
- Player movement and collectibles
- Map validation and parsing

Requirements
------------
- Linux
- `minilibx` (X11), `gcc`, `make`

Build
-----
From the project root:

```
make
```

Makefile highlights:

```
CC = cc
FLAG = -Wall -Wextra -Werror -g3
MLX_FLAG = -lX11 -lXext
```

The build depends on `lib/libft/libft.a`, `lib/ft_printf/ft_printf.a`, and `lib/minilibx-linux/libmlx.a`. The Makefile automatically builds these libraries when needed.

Run the game:

```
./so_long maps/example.ber
```

Usage
-----
Run the game with a map file:

```
./so_long maps/example.ber
```

Project Layout
--------------
- `assets/` — image assets
- `srcs/`, `srcs_bonus/` — source files
- `lib/` — libraries (e.g., minilibx)

Notes
-----
- Map files usually have a `.ber` extension and must follow the required rectangular layout with walls around the edges.

Author / Attribution
--------------------
Author: ankammer

License
-------
Unlicensed.
