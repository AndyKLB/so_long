/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:20:42 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/25 17:46:34 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	quit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_backg);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collec);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_enemy);
	mlx_destroy_image(game->mlx, game->img_happy);
	mlx_destroy_image(game->mlx, game->img_count);
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

void	print_count_on_screen(t_game *game)
{
	char	*count;
	char	*count_message;

	count_message = "Movement = ";
	count = ft_itoa(game->nbr_player_move);
	count_message = ft_strjoin_count(count_message, count);
	draw_img(game, game->img_count, 0, 0);
	draw_img(game, game->img_count, 1, 0);
	draw_img(game, game->img_count, 2, 0);
	draw_img(game, game->img_count, 3, 0);
	mlx_string_put(game->mlx, game->win, 16, 16, 0x000000, count_message);
	free(count);
	free(count_message);
}

int	pressed_key(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		quit_game(game);
	else
	{
		player_wasd(game, keysym);
		print_count_on_screen(game);
	}
	return (0);
}

void	hook_handle(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, pressed_key, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, quit_game, game);
}
