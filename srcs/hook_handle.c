/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:20:42 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/22 16:08:14 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_backg);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collec);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	player_wasd(t_game *game, int keysym)
{
	if ((keysym == XK_Up || keysym == XK_w) && game->map[game->y_player
			- 1][game->x_player] != '1')
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if ((keysym == XK_Down || keysym == XK_s) && game->map[game->y_player
			+ 1][game->x_player] != '1')
	{
		game->y_player += 1;
		player_s(game);
	}
	else if ((keysym == XK_Left || keysym == XK_a)
		&& game->map[game->y_player][game->x_player - 1] != '1')
	{
		game->x_player -= 1;
		player_a(game);
	}
	else if ((keysym == XK_Right || keysym == XK_d)
		&& game->map[game->y_player][game->x_player + 1] != '1')
	{
		game->x_player += 1;
		player_d(game);
	}
	return (0);
}

int	pressed_key(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		quit_game(game);
	else
		player_wasd(game, keysym);
	return (0);
}

void	hook_handle(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, pressed_key, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, quit_game, game);
}
