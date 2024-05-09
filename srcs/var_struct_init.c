/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_struct_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:39:26 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/29 12:25:54 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_win_size(t_game *game)
{
	int	i;

	if (!game->map || !game->map[0])
		return ;
	game->map_w = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i * 32;
}

int	xpm_to_img(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image(game->mlx,
			"assets/img/xpm_files/0.xpm", &game->img_h, &game->img_w);
	if (!game->img_backg)
		return (1);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/img/xpm_files/E.xpm", &game->img_h, &game->img_w);
	if (!game->img_exit)
		return (free(game->img_backg), 1);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/img/xpm_files/1.xpm", &game->img_h, &game->img_w);
	if (!game->img_wall)
		return (free(game->img_backg), free(game->img_exit), 1);
	game->img_collec = mlx_xpm_file_to_image(game->mlx,
			"assets/img/xpm_files/C.xpm", &game->img_h, &game->img_w);
	if (!game->img_collec)
		return (free(game->img_backg), free(game->img_exit),
			free(game->img_wall), 1);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/img/xpm_files/PR.xpm", &game->img_h, &game->img_w);
	if (!game->img_player)
		return (free(game->img_backg), free(game->img_exit),
			free(game->img_wall), free(game->img_collec), 1);
	return (0);
}

void	get_pec(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				(game->nbr_player)++;
				game->y_player = y;
				game->x_player = x;
			}
			else if (game->map[y][x] == 'E')
			{
				(game->nbr_exit)++;
				game->y_exit = y;
				game->x_exit = x;
			}
			else if (game->map[y][x] == 'C')
				(game->nbr_collec)++;
		}
	}
}

void	var_struct_init(t_game *game)
{
	game->nbr_player_move = 0;
	game->nbr_player = 0;
	game->nbr_collec = 0;
	game->nbr_exit = 0;
	game->x_player = 0;
	game->y_player = 0;
	game->map_h = 0;
	game->map_w = 0;
	game->img_w = 0;
	game->img_h = 0;
	get_win_size(game);
	get_pec(game);
}
