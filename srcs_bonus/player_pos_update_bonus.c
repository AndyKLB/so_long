/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos_update_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:00:11 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/25 16:01:20 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_update_image(char wasd, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (wasd == 'w')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"./assets/img/xpm_files/PU.xpm", &game->img_w, &game->img_h);
	if (wasd == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"./assets/img/xpm_files/PL.xpm", &game->img_w, &game->img_h);
	if (wasd == 's')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"./assets/img/xpm_files/PD.xpm", &game->img_w, &game->img_h);
	if (wasd == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"./assets/img/xpm_files/PR.xpm", &game->img_w, &game->img_h);
}

void	player_w(t_game *game)
{
	player_update_image('w', game);
	if (game->map[game->y_player][game->x_player] == 'C')
	{
		draw_img(game, game->img_happy, game->x_player, game->y_player);
		game->map[game->y_player][game->x_player] = '0';
		if (game->map[game->y_player + 1][game->x_player] != 'E')
			game->map[game->y_player + 1][game->x_player] = '0';
		draw_img(game, game->img_happy, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player, game->y_player + 1);
		game->nbr_collec--;
		if (game->nbr_collec == 0)
			draw_img(game, game->img_exit, game->x_exit, game->y_exit);
	}
	else if (game->map[game->y_player][game->x_player] == 'E'
		&& game->nbr_collec == 0)
		quit_game(game);
	else if (game->map[game->y_player][game->x_player] == 'N')
		quit_game(game);
	else
	{
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player, game->y_player + 1);
	}
	game->nbr_player_move++;
	ft_printf("Movement : %d\r\033[0m", game->nbr_player_move);
}

void	player_a(t_game *game)
{
	player_update_image('a', game);
	if (game->map[game->y_player][game->x_player] == 'C')
	{
		draw_img(game, game->img_happy, game->x_player, game->y_player);
		game->map[game->y_player][game->x_player] = '0';
		if (game->map[game->y_player][game->x_player + 1] != 'E')
			game->map[game->y_player][game->x_player + 1] = '0';
		draw_img(game, game->img_happy, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player + 1, game->y_player);
		game->nbr_collec--;
		if (game->nbr_collec == 0)
			draw_img(game, game->img_exit, game->x_exit, game->y_exit);
	}
	else if (game->map[game->y_player][game->x_player] == 'E'
		&& game->nbr_collec == 0)
		quit_game(game);
	else if (game->map[game->y_player][game->x_player] == 'N')
		quit_game(game);
	else
	{
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player + 1, game->y_player);
	}
	game->nbr_player_move++;
	ft_printf("Movement : %d\r\033[0m", game->nbr_player_move);
}

void	player_s(t_game *game)
{
	player_update_image('s', game);
	if (game->map[game->y_player][game->x_player] == 'C')
	{
		game->map[game->y_player][game->x_player] = '0';
		if (game->map[game->y_player - 1][game->x_player] != 'E')
			game->map[game->y_player - 1][game->x_player] = '0';
		draw_img(game, game->img_happy, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player, game->y_player - 1);
		game->nbr_collec--;
		if (game->nbr_collec == 0)
			draw_img(game, game->img_exit, game->x_exit, game->y_exit);
	}
	else if (game->map[game->y_player][game->x_player] == 'E'
		&& game->nbr_collec == 0)
		quit_game(game);
	else if (game->map[game->y_player][game->x_player] == 'N')
		quit_game(game);
	else
	{
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player, game->y_player - 1);
	}
	game->nbr_player_move++;
	ft_printf("Movement : %d\r\033[0m", game->nbr_player_move);
}

void	player_d(t_game *game)
{
	player_update_image('d', game);
	if (game->map[game->y_player][game->x_player] == 'C')
	{
		draw_img(game, game->img_happy, game->x_player, game->y_player);
		game->map[game->y_player][game->x_player] = '0';
		if (game->map[game->y_player][game->x_player - 1] != 'E')
			game->map[game->y_player][game->x_player - 1] = '0';
		draw_img(game, game->img_happy, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player - 1, game->y_player);
		game->nbr_collec--;
		if (game->nbr_collec == 0)
			draw_img(game, game->img_exit, game->x_exit, game->y_exit);
	}
	else if (game->map[game->y_player][game->x_player] == 'E'
		&& game->nbr_collec == 0)
		quit_game(game);
	else if (game->map[game->y_player][game->x_player] == 'N')
		quit_game(game);
	else
	{
		draw_img(game, game->img_player, game->x_player, game->y_player);
		draw_img(game, game->img_backg, game->x_player - 1, game->y_player);
	}
	game->nbr_player_move++;
	ft_printf("Movement : %d\r\033[0m", game->nbr_player_move);
}
