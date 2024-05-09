/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:00:11 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/29 12:31:23 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_w(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'C')
	{
		game->map[game->y_player][game->x_player] = '0';
		if (game->map[game->y_player + 1][game->x_player] != 'E')
			game->map[game->y_player + 1][game->x_player] = '0';
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player, game->y_player + 1);
		game->nbr_collec--;
		if (game->nbr_collec == 0)
			draw_img(game, game->img_exit, game->x_exit, game->y_exit);
	}
	else if (game->map[game->y_player][game->x_player] == 'E'
		&& game->nbr_collec == 0)
		quit_game(game);
	else
	{
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player, game->y_player + 1);
	}
	game->nbr_player_move++;
	ft_printf("movement: %d\r\033[0m", game->nbr_player_move);
}

void	player_a(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'C')
	{
		game->map[game->y_player][game->x_player] = '0';
		if (game->map[game->y_player][game->x_player + 1] != 'E')
			game->map[game->y_player][game->x_player + 1] = '0';
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player + 1, game->y_player);
		game->nbr_collec--;
		if (game->nbr_collec == 0)
			draw_img(game, game->img_exit, game->x_exit, game->y_exit);
	}
	else if (game->map[game->y_player][game->x_player] == 'E'
		&& game->nbr_collec == 0)
		quit_game(game);
	else
	{
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player + 1, game->y_player);
	}
	game->nbr_player_move++;
	ft_printf("movement: %d\r\033[0m", game->nbr_player_move);
}

void	player_s(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'C')
	{
		game->map[game->y_player][game->x_player] = '0';
		if (game->map[game->y_player - 1][game->x_player] != 'E')
			game->map[game->y_player - 1][game->x_player] = '0';
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player, game->y_player - 1);
		game->nbr_collec--;
		if (game->nbr_collec == 0)
			draw_img(game, game->img_exit, game->x_exit, game->y_exit);
	}
	else if (game->map[game->y_player][game->x_player] == 'E'
		&& game->nbr_collec == 0)
		quit_game(game);
	else
	{
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player, game->y_player - 1);
	}
	game->nbr_player_move++;
	ft_printf("movement: %d\r\033[0m", game->nbr_player_move);
}

void	player_d(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'C')
	{
		game->map[game->y_player][game->x_player] = '0';
		if (game->map[game->y_player][game->x_player - 1] != 'E')
			game->map[game->y_player][game->x_player - 1] = '0';
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player - 1, game->y_player);
		game->nbr_collec--;
		if (game->nbr_collec == 0)
			draw_img(game, game->img_exit, game->x_exit, game->y_exit);
	}
	else if (game->map[game->y_player][game->x_player] == 'E'
		&& game->nbr_collec == 0)
		quit_game(game);
	else
	{
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player - 1, game->y_player);
	}
	game->nbr_player_move++;
	ft_printf("movement: %d\r\033[0m", game->nbr_player_move);
}
