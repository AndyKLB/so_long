/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:43:45 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/25 10:46:29 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_wall(char **map, int y, int x)
{
	if (map[y][x] == '1')
		return (1);
	else
		return (0);
}

int	is_enemy(char **map, int y, int x)
{
	if (map[y][x] == 'N')
		return (1);
	else
		return (0);
}

void	flood_map(t_game *copy, int y, int x)
{
	if (is_wall(copy->map, y, x) || is_enemy(copy->map, y, x))
		return ;
	if (copy->map[y][x] == 'C')
		(copy->nbr_collec)--;
	else if (copy->map[y][x] == 'E')
		(copy->nbr_exit)--;
	copy->map[y][x] = '1';
	flood_map(copy, y - 1, x);
	flood_map(copy, y + 1, x);
	flood_map(copy, y, x - 1);
	flood_map(copy, y, x + 1);
}

int	is_valid_path(t_game *game)
{
	t_game	*game_copy;
	int		result;

	result = 0;
	game_copy = copy_struct(game);
	if (!game_copy)
		return (0);
	flood_map(game_copy, game_copy->y_player, game_copy->x_player);
	if (game_copy->nbr_collec == 0 && game_copy->nbr_exit == 0)
		result = 1;
	else
		ft_printf("error:\ninvalid path on the map\n");
	free_map(game_copy->map);
	free(game_copy);
	game_copy = NULL;
	return (result);
}
