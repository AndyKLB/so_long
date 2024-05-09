/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:50:41 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/29 12:35:56 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_collec;
	void	*img_exit;
	void	*img_enemy;
	void	*img_happy;
	void	*img_count;
	char	**map;
	int		nbr_player_move;
	int		nbr_player;
	int		nbr_collec;
	int		nbr_exit;
	int		nbr_enemy;
	int		x_player;
	int		y_player;
	int		x_exit;
	int		y_exit;
	int		map_h;
	int		map_w;
	int		img_w;
	int		img_h;

}			t_game;

// check argv
char		**map_reader(char *map_path);

// check map
int			map_is_valid(t_game *game);
int			is_valid_path(t_game *game);
int			map_is_rec(char **map);
int			map_no_invalid_arg(char **map);
int			map_is_wall(char **map);
int			map_arg_present(t_game *game);
int			is_wall(char **map, int y, int x);
void		flood_map(t_game *game, int y, int x);

// init
void		var_struct_init(t_game *game);
int			game_init(t_game *game);
void		get_pec(t_game *game);
void		get_win_size(t_game *game);
int			xpm_to_img(t_game *game);
int			xpm_enemy_to_img(t_game *game);

void		error_message(t_game *game);

// draw
void		draw_img(t_game *game, void *img, int x, int y);
void		draw_map(t_game *game);

// hook
void		hook_handle(t_game *game);
int			pressed_key(int keysym, t_game *game);
int			player_wasd(t_game *game, int keysym);
void		player_w(t_game *game);
void		player_a(t_game *game);
void		player_s(t_game *game);
void		player_d(t_game *game);
void		player_update_image(char wasd, t_game *game);
void		enemy_init_bonus(t_game *game);

// utils
t_game		*copy_struct(t_game *game);
void		free_map(char **map);
char		*ft_strjoin_count(char const *s1, char const *s2);
char		**copy_map(char **original);
int			quit_game(t_game *game);

#endif